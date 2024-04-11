#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 1000010;
constexpr int HMOD = 1000000007;

char scram[NMAX];
ll pow10[NMAX], valEndAt[NMAX];
int n;

ll hashVal(int i, int j) {
	return (valEndAt[j + 1] - (valEndAt[i] * pow10[j - i + 1] % HMOD) + HMOD) % HMOD;
}

vector<int> digitList(int a, int b) {
	vector<int> ans;
	for (int i = b; i >= a; --i) ans.push_back(scram[i] - '0');
	return ans;
}

vector<int> addNumbers(vector<int> &an, vector<int> &bn) {
	vector<int> ans(max(an.size(), bn.size()));
	for (int i = 0; i < an.size(); ++i) ans[i] += an[i];
	for (int i = 0; i < bn.size(); ++i) ans[i] += bn[i];
	for (int i = 0; i + 1 < ans.size(); ++i) {
		if (ans[i] >= 10) {
			ans[i+1] += ans[i] / 10;
			ans[i] %= 10;
		}
	}
	if (ans.back() >= 10) {
		int newDig = ans.back() / 10;
		ans.back() %= 10;
		ans.push_back(newDig);
	}
	return ans;
}

void checkValid(int a, int b, int c) {
//	printf("%d %d %d\n", a, b, c);
	vector<int> checkLeading{a, b, c, n};
	for (int i = 0; i + 1 < 4; ++i) {
		if (scram[checkLeading[i]] == '0' && checkLeading[i+1] - checkLeading[i] > 1) return;
	}
//	printf("%lld %lld %lld\n", hashVal(0, b-1), hashVal(b, c - 1), hashVal(c, n - 1));
	if ((hashVal(0, b - 1) + hashVal(b, c - 1)) % HMOD != hashVal(c, n - 1)) return;
	vector<int> aDigits = digitList(0, b - 1), bDigits = digitList(b, c - 1), cDigits = digitList(c, n - 1);
	if (addNumbers(aDigits, bDigits) != cDigits) return;
	// print the answer if we get here
	for (int i = a; i < b; ++i) printf("%c", scram[i]);
	printf("+");
	for (int i = b; i < c; ++i) printf("%c", scram[i]);
	printf("=");
	for (int i = c; i < n; ++i) printf("%c", scram[i]);
	printf("\n");
	exit(0);
}


int main() {
	scanf("%s", scram);
	n = strlen(scram);
	pow10[0] = 1;
	for (int i = 1; i < NMAX; ++i) pow10[i] = (pow10[i-1] * 10) % HMOD;
	valEndAt[1] = (scram[0] - '0');
	for (int i = 1; i < n; ++i) valEndAt[i + 1] = (10 * valEndAt[i] + (scram[i] - '0')) % HMOD;
	vector<pair<int, pair<int, int>>> lenToTry;
	for (int ansLen = 1; ansLen <= n - 2; ++ansLen) {
		// (ansLen, n - 2 * ansLen, ansLen) and (ansLen - 1, n - 2 
		lenToTry.emplace_back(ansLen, make_pair(n - 2 * ansLen, ansLen));
		lenToTry.emplace_back(ansLen - 1, make_pair(n - 2 * ansLen + 1, ansLen));
		lenToTry.emplace_back(n - 2 * ansLen + 1, make_pair(ansLen - 1, ansLen));
		lenToTry.emplace_back(n - 2 * ansLen, make_pair(ansLen, ansLen));
	}
	for (auto a_b_c : lenToTry) {
		int a, b, c;
		forward_as_tuple(a, tie(b, c)) = a_b_c;
		if (a <= 0 || b <= 0 || c <= 0) continue;
		checkValid(0, a, a + b);
	}
	return 0;
}