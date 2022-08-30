#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

char vc_[30];
int N, M, L;
int kind[30];
vector<int> rule[400];
char S[202];

bool wf[400][400];

bool isok(string &str)
{
	bool vis[404];
	for (int i = 0; i < 2 * N; ++i) vis[i] = false;
	for (int i = 0; i < str.size(); ++i) {
		int ia = i * 2 + kind[str[i] - 'a'];
		for (int j = 0; j < 2 * N; ++j) if (wf[ia][j]) vis[j] = true;
	}
	//printf("%s\n", str.c_str());
	for (int i = 0; i < N; ++i) if (vis[i * 2] && vis[i * 2 + 1]) return false;
	//puts("is ok");
	return true;
}

int main()
{
	scanf("%s%d%d", vc_, &N, &M);
	L = strlen(vc_);
	for (int i = 0; i < L; ++i) kind[i] = (vc_[i] == 'V' ? 0 : 1);

	for (int i = 0; i < M; ++i) {
		int p, q; char ta[2], tb[2];
		scanf("%d%s%d%s", &p, ta, &q, tb);
	//	printf("%d %s %d %s\n", p, ta, q, tb);
		if (ta[0] == 'V') ta[0] = 0; else ta[0] = 1;
		if (tb[0] == 'V') tb[0] = 0; else tb[0] = 1;
		--p; --q;
	//	printf("%d -> %d\n", p * 2 + ta[0], q * 2 + tb[0]);
		rule[p * 2 + ta[0]].push_back(q * 2 + tb[0]);
		rule[q * 2 + (1 - tb[0])].push_back(p * 2 + (1 - ta[0]));
	}
	scanf("%s", S);

	for (int i = 0; i < 2 * N; ++i) {
		for (int j = 0; j < 2 * N; ++j) wf[i][j] = (i == j);
	}
	for (int i = 0; i < 2 * N; ++i) {
		for (int j : rule[i]) wf[i][j] = true;
	}
	for (int i = 0; i < 2 * N; ++i) {
		for (int j = 0; j < 2 * N; ++j) {
			for (int k = 0; k < 2 * N; ++k) {
				wf[j][k] |= wf[j][i] && wf[i][k];
			}
		}
	}
	//for (int i = 0; i < 2 * N; ++i) {
	//	for (int j = 0; j < 2 * N; ++j) printf("%d ", wf[i][j]);
	//	puts("");
	//}
	for (int i = 0; i < 2 * N; ++i) {
		if (wf[i][i ^ 1] && wf[i ^ 1][i]) {
			puts("-1");
			return 0;
		}
	}
	{
		string pq = S;
		if (isok(pq)) {
			printf("%s\n", S);
			return 0;
		}
	}
	bool unitary = true;
	for (int i = 1; i < L; ++i) if (kind[i] != kind[0]) unitary = false;
	if (unitary) {
		puts("-1");
		return 0;
	}
	for (int p = N - 1; p >= 0; --p) {
		bool done[2];
		done[0] = done[1] = false;
		string str;
		for (int i = 0; i < p; ++i) str.push_back(S[i]);
		str.push_back('*');
		for (char c = S[p] + 1; c < ('a' + L); ++c) {
			if (done[kind[c - 'a']]) continue;
			done[kind[c - 'a']] = true;
			str[p] = c;
			if (isok(str)) {
				for (int i = p + 1; i < N; ++i) {
					str.push_back('*');
					done[0] = done[1] = false;
					for (char d = 'a'; d < ('a' + L); ++d) {
						if (done[kind[d]]) continue;
						str[i] = d;
						if (isok(str)) break;
					}
				}
				printf("%s\n", str.c_str());
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}