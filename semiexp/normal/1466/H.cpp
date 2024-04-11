#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
#define SUB(X,Y) ((X) = ((X) + MOD - (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

i64 modpow(i64 x, int p = MOD - 2) {
	if (p == 0) return 1;
	i64 tmp = modpow(x, p / 2);
	tmp = tmp * tmp % MOD;
	if (p % 2 == 1) tmp = tmp * x % MOD;
	return tmp;
}

int N, P[44];

int uf[505050];

int root(int p) {
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}
bool join(int p, int q) {
	p = root(p);
	q = root(q);
	if (p == q) return false;
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

vector<int> szs;
i64 pows[10000];

i64 sub[42][42];

map<vector<int>, i64> memo;

i64 solve(const vector<int>& seq);

void solve_sub(const vector<int>& seq, vector<int>& new_seq, int p, i64& sto) {
	if (p == seq.size()) {
		if (seq == new_seq) return;
		i64 base = solve(new_seq);

		int used = 0;
		for (int i = 0; i < seq.size(); ++i) used += szs[i] * (seq[i] - new_seq[i]);
		for (int i = 0; i < seq.size(); ++i) {
			i64 tmp = pows[used * szs[i]] - 1;
			for (int j = 0; j < new_seq[i]; ++j) base = base * tmp % MOD;
		}
		ADD(sto, base);
		return;
	}
	for (int i = 0; i <= seq[p]; ++i) {
		new_seq[p] = i;
		solve_sub(seq, new_seq, p + 1, sto);
	}
}

i64 fact[44], facti[44];
i64 C[44][44];

i64 solve(const vector<int>& seq) {
	if (memo.count(seq)) return memo[seq];

	bool flg = true;
	for (int i = 0; i < seq.size(); ++i) {
		if (seq[i] != 0) flg = false;
	}
	if (flg) {
		return memo[seq] = 1;
	}
/*
	vector<int> seq2(seq.size(), -1);
	solve_sub(seq, seq2, 0, ret);
*/

	vector<vector<int>> nxseq;  // take as "maximum"
	vector<i64> val;

	int n_pat = 1;
	for (int i = 0; i < seq.size(); ++i) n_pat *= seq[i] + 1;
	for (int i = 0; i < n_pat; ++i) {
		vector<int> tmp;
		int w = i;
		for (int j = 0; j < seq.size(); ++j) {
			tmp.push_back(w % (seq[j] + 1));
			w /= seq[j] + 1;
		}
		nxseq.push_back(tmp);
		if (i == 0) val.push_back(0);
		else {
			int up = 0, dw = 0;
			i64 v = 1;
			for (int j = 0; j < seq.size(); ++j) {
				dw += szs[j] * (seq[j] - tmp[j]);
			}
			for (int j = 0; j < seq.size(); ++j) {
				v = v * sub[dw][szs[j] * tmp[j]] % MOD * C[seq[j]][tmp[j]] % MOD;
			}
			for (int j = 0; j < seq.size(); ++j) nxseq[i][j] = seq[j] - nxseq[i][j];
			v = v * solve(nxseq[i]) % MOD;
//			ADD(ret, solve(nxseq[i]) * val[i]);
			for (int j = 0; j < seq.size(); ++j) nxseq[i][j] = seq[j] - nxseq[i][j];

			val.push_back(v);
		}
	}
	//printf("now");
	//for (int i = 0; i < seq.size(); ++i) printf(" %d", seq[i]);
	//puts("");

	i64 adder = 1;
	for (int i = 0; i < seq.size(); ++i) {
		// for (int j = 0; j < nxseq.size(); ++j) {
		for (int j = nxseq.size() - 1; j >= 0; --j) {
			for (int k = nxseq[j][i] + 1; k <= seq[i]; ++k) {
				SUB(val[j], val[j + adder * (k - nxseq[j][i])] * C[k][nxseq[j][i]]);
			}
		}
		adder *= seq[i] + 1;
	}
	/*for (int i = 0; i < nxseq.size(); ++i) {
		for (int j = 0; j < seq.size(); ++j) printf(" %d", nxseq[i][j]);
		printf(" -> %lld\n", val[i]);
	}*/
	i64 ret = 0;
	for (int i = 1; i < nxseq.size(); ++i) {
		/*
		for (int j = 0; j < seq.size(); ++j) nxseq[i][j] = seq[j] - nxseq[i][j];
		ADD(ret, solve(nxseq[i]) * val[i]);
		for (int j = 0; j < seq.size(); ++j) nxseq[i][j] = seq[j] - nxseq[i][j];
		*/
		ADD(ret, val[i]);
	}

	//for (int i = 0; i < seq.size(); ++i) printf("%d ", seq[i]);
	//printf("-> %lld\n", ret);
	return memo[seq] = ret;
}

void precomp() {
	pows[0] = 1;
	for (int i = 1; i < 10000; ++i) {
		pows[i] = pows[i - 1] * 2 % MOD;
		if (pows[i] == 1) puts("angry");
	}

	fact[0] = 1;
	for (int i = 1; i <= 40; ++i) fact[i] = fact[i - 1] * i % MOD;
	for (int i = 0; i <= 40; ++i) facti[i] = modpow(fact[i]);
	for (int i = 0; i <= 40; ++i) {
		for (int j = 0; j <= i; ++j) C[i][j] = fact[i] * facti[j] % MOD * facti[i - j] % MOD;
	}

	for (int i = 0; i <= N - 1; ++i) {
		i64 tmp = 0;
		for (int j = 0; j <= i; ++j) {
			ADD(tmp, fact[i] * facti[i - j] % MOD * fact[N - 1 - j]);
		}
		sub[i][0] = 1;
		for (int j = 1; j <= 40; ++j) sub[i][j] = sub[i][j - 1] * tmp % MOD;
	}
}

int main()
{
	map<int, int> by_size;
	if (false) {
		by_size.emplace(1, 7);
		by_size.emplace(2, 4);
		by_size.emplace(3, 2);
		by_size.emplace(4, 2);
		by_size.emplace(5, 1);
		by_size.emplace(6, 1);
		N = 40;
	} else {
		scanf("%d", &N);

		for (int i = 0; i < N; ++i) {
			scanf("%d", P + i);
			--P[i];
			uf[i] = -1;
		}
		for (int i = 0; i < N; ++i) join(i, P[i]);

		vector<int> cycs;
		for (int i = 0; i < N; ++i) {
			if (root(i) == i) cycs.push_back(-uf[i]);
		}
		for (int c : cycs) by_size[c] += 1;
	}

	precomp();

	vector<int> init;
	for (auto& p : by_size) {
		szs.push_back(p.first);
		init.push_back(p.second);
	}

	printf("%lld\n", solve(init));
	return 0;
}