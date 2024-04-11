#include <bits/stdc++.h>

using namespace std;
constexpr int SIGMA = 300;
constexpr int NMAX = 300010;
using ll = long long;
constexpr ll MOD = 1000000007;

// i had to learn lots of string algo for this haha

pair<int, int> getIPair(vector<int> &cperm, vector<int> &equivNames, int n, int rnd, int i) {
	return pair<int, int>(equivNames[cperm[i]], equivNames[(cperm[i] + (1 << (rnd - 1))) % n]);
}

// ripped from cp-algorithms
vector<int> sortedShifts(string s) {
	int n = s.size();
	vector<int> cperm(n), equivNames(n);
	vector<int> bilang(max(SIGMA, n));
	// run a counting sort of cperm, key is s
	for (int i = 0; i < n; ++i) ++bilang[s[i]];
	for (int i = 1; i < SIGMA; ++i) bilang[i] += bilang[i-1];
	for (int i = 0; i < n; ++i) cperm[--bilang[s[i]]] = i;
	equivNames[cperm[0]] = 0;
	for (int i = 1; i < n; ++i) {
		equivNames[cperm[i]] = equivNames[cperm[i-1]] + (s[cperm[i]] != s[cperm[i-1]] ? 1 : 0);
	}
	for (int rnd = 1; (1 << (rnd - 1)) < n; ++rnd) {
		// generate a sort of (cperm[i], cperm[(i + (1 << (rnd - 1))) % n])
		vector<int> pOnSeconds(n); // this is a list of i sorted by their second element
		for (int i = 0; i < n; ++i) {
			pOnSeconds[i] = cperm[i] - (1 << (rnd - 1));
			if (pOnSeconds[i] < 0) pOnSeconds[i] += n;
		}
		// sort pOnSeconds by the first element
		bilang.assign(bilang.size(), 0);
		for (int i = 0; i < n; ++i) ++bilang[equivNames[pOnSeconds[i]]];
		for (int i = 1; i < bilang.size(); ++i) bilang[i] += bilang[i-1];
		for (int i = n - 1; i >= 0; --i) {
			cperm[--bilang[equivNames[pOnSeconds[i]]]] = pOnSeconds[i];
		}
		vector<int> newENames(n);
		newENames[cperm[0]] = 0;
		for (int i = 1; i < n; ++i) {
			pair<int, int> cpair = getIPair(cperm, equivNames, n, rnd, i);
			pair<int, int> prevPair = getIPair(cperm, equivNames, n, rnd, i-1);
			newENames[cperm[i]] = newENames[cperm[i-1]] + (cpair != prevPair ? 1 : 0);
		}
		equivNames = newENames;
	}
	return cperm;
}

vector<int> lcpArray(string &s, vector<int> &sufPerm) {
	int n = s.size();
	vector<int> ans(n - 1), posInSArr(n);
	for (int i = 0; i < n; ++i) {
		posInSArr[sufPerm[i]] = i;
	}
	int checkStart = 0;
	for (int i = 0; i < n; ++i) {
		if (posInSArr[i] == n - 1) checkStart = 0;
		else {
			int nextInSuffArr = sufPerm[posInSArr[i] + 1];
			while (i + checkStart < n && nextInSuffArr + checkStart < n && 
					s[i + checkStart] == s[nextInSuffArr + checkStart]) ++checkStart;
			ans[posInSArr[i]] = checkStart;
			if (checkStart) --checkStart;
		}
	}
	return ans;
}

struct MISparseTable {
	int n;
	vector<vector<int>> table;
	vector<int> _plog, arr;
	int lesserIndex(int i, int j) {
		if (make_pair(arr[i], i) < make_pair(arr[j], j)) return i;
		else return j;
	}
	MISparseTable() {}
	MISparseTable(vector<int> &init) : n(init.size()), _plog(init.size() + 1), arr(init) {
		_plog[0] = -1;
		for (int i = 1; i <= n; ++i) {
			_plog[i] = _plog[i-1] + ((i & (i - 1)) == 0 ? 1 : 0);
		}
		table = vector<vector<int>>(_plog[n] + 1, vector<int>(n));
		for (int i = 0; i < n; ++i) table[0][i] = i;
		for (int layer = 1; (1 << layer) <= n; ++layer) {
			for (int i = 0; i + (1 << layer) <= n; ++i) {
				int i1 = table[layer-1][i], i2 = table[layer-1][i + (1 << (layer - 1))];
				table[layer][i] = lesserIndex(i1, i2);
			}
		}
	}
	int getMinI(int i, int j) {
		int ltf = _plog[j - i + 1];
		return lesserIndex(table[ltf][i], table[ltf][j + 1 - (1 << ltf)]);
	}
};

struct PSumTable {
	int n;
	vector<int> psum;
	PSumTable() {}
	PSumTable(vector<int> init) : n(init.size()), psum(init.size() + 1) {
		for (int i = 1; i <= n; ++i) psum[i] = psum[i-1] + init[i-1];
	}
	ll getSum(int i, int j) {
		return psum[j + 1] - psum[i];
	}
};

MISparseTable astronomia;
vector<int> biggLCP;
PSumTable stringOccs[3];
ll ans[NMAX];

void hanapinAngSagot(int sai, int saj, int pLength) {
	if (sai >= saj) return;
	int fchildEnd = astronomia.getMinI(sai, saj - 1);
	int cnLength = biggLCP[fchildEnd];
	// the strings from parent to here have length (pLength, cnLength]
	ll childTriples = 1;
	for (int k = 0; k < 3; ++k) childTriples = childTriples * stringOccs[k].getSum(sai, saj) % MOD;
	ans[pLength + 1] += childTriples;
	ans[cnLength + 1] -= childTriples;
	hanapinAngSagot(sai, fchildEnd, cnLength);
	hanapinAngSagot(fchildEnd + 1, saj, cnLength);
}

int main() {
	string a, b, c; cin >> a >> b >> c;
	a += '!', b += '#', c += '$';
	string biggString = a + b + c;
	vector<int> biggSA = sortedShifts(biggString);
	biggLCP = lcpArray(biggString, biggSA);
	vector<string> sTable{a, b, c};
	vector<pair<int, int>> sInOrder(biggString.size());
	int sal = biggSA.size();
	for (int i = 0; i < sal; ++i) {
		if (biggSA[i] < a.size()) sInOrder[i] = make_pair(0, biggSA[i]);
		else if (biggSA[i] < a.size() + b.size()) sInOrder[i] = make_pair(1, biggSA[i] - a.size());
		else sInOrder[i] = make_pair(2, biggSA[i] - (a.size() + b.size()));
	}
	vector<vector<int>> salPerString(3, vector<int>(sal, 0));
	for (int i = 0; i < sal; ++i) {
		if (sInOrder[i].second + 1 < sTable[sInOrder[i].first].size()) {
			salPerString[sInOrder[i].first][i] = 1;
		}
	}
	for (int k = 0; k < 3; ++k) stringOccs[k] = PSumTable(salPerString[k]);
	astronomia = MISparseTable(biggLCP);
	hanapinAngSagot(0, sal - 1, 0);
	for (int i = 1; i < NMAX; ++i) ans[i] = (ans[i-1] + ans[i]) % MOD;
	int sToPrint = min(a.size(), min(b.size(), c.size()));
	for (int i = 1; i < sToPrint; ++i) printf("%lld ", (ans[i] % MOD + MOD) % MOD);
	printf("\n");
}