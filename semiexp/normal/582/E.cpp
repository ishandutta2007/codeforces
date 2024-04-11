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
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

char S[505];
int p;

void zeta(vector<int> &seq)
{
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1 << 16); ++j) if ((j & (1 << i)) == 0) {
			ADD(seq[j ^ (1 << i)], seq[j]);
		}
	}
}
void unzeta(vector<int> &seq)
{
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1 << 16); ++j) if ((j & (1 << i)) == 0) {
			ADD(seq[j ^ (1 << i)], MOD - seq[j]);
		}
	}
}
void izeta(vector<int> &seq)
{
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1 << 16); ++j) if ((j & (1 << i)) != 0) {
			ADD(seq[j ^ (1 << i)], seq[j]);
		}
	}
}
void unizeta(vector<int> &seq)
{
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < (1 << 16); ++j) if ((j & (1 << i)) != 0) {
			ADD(seq[j ^ (1 << i)], MOD - seq[j]);
		}
	}
}
vector<int> seqor(vector<int> &s1, vector<int> &s2)
{
	vector<int> ret;
	zeta(s1);
	zeta(s2);
	for (int i = 0; i < (1 << 16); ++i) ret.push_back((int)((i64)s1[i] * s2[i] % MOD));
	unzeta(ret);
	unzeta(s1);
	unzeta(s2);
	return ret;
}
vector<int> seqand(vector<int> &s1, vector<int> &s2)
{
	vector<int> ret;
	izeta(s1);
	izeta(s2);
	for (int i = 0; i < (1 << 16); ++i) ret.push_back((int)((i64)s1[i] * s2[i] % MOD));
	unizeta(ret);
	unizeta(s1);
	unizeta(s2);
	return ret;
}
vector<int> add(vector<int> &s1, vector<int> &s2)
{
	vector<int> ret;
	for (int i = 0; i < (1 << 16); ++i) ret.push_back((s1[i] + s2[i]) % MOD);
	return ret;
}

vector<int> parse()
{
	if (S[p] == '(') {
		++p;
		vector<int> lf = parse();
		++p;
		char op = S[p++];
		++p;
		vector<int> rg = parse();
		++p;
		if (op == '&') return seqand(lf, rg);
		else if (op == '|') return seqor(lf, rg);
		vector<int> a = seqand(lf, rg), o = seqor(lf, rg);
		return add(a, o);
	} else {
		vector<int> seq(1 << 16, 0);
		char c = S[p++];
		for (int i = 0; i < 4; ++i) {
			if (c == '?' || c == ('A' + i)) {
				int mask = 0;
				for (int j = 0; j < 16; ++j) if (j & (1 << i)) mask |= 1 << j;
				seq[mask] += 1;
			}
			if (c == '?' || c == ('a' + i)) {
				int mask = 0;
				for (int j = 0; j < 16; ++j) if ((j & (1 << i)) == 0) mask |= 1 << j;
				seq[mask] += 1;
			}
		}
		return seq;
	}
}

int cond[16];

int main()
{
	scanf("%s", S);
	p = 0;

	vector<int> seq = parse();
	
	int N;
	scanf("%d", &N);
	for (int i = 0; i < 16; ++i) cond[i] = -1;
	for (int i = 0; i < N; ++i) {
		int a, b, c, d, e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		cond[a | (b << 1) | (c << 2) | (d << 3)] = e;
	}
	int ret = 0;
	for (int i = 0; i < (1 << 16); ++i) {
		bool isok = true;
		for (int j = 0; j < 16; ++j) {
			if (cond[j] == -1 || ((i >> j) & 1) == cond[j]) {
			} else isok = false;
		}
		if (isok) ADD(ret, seq[i]);
	}
	printf("%d\n", ret);
	return 0;
}