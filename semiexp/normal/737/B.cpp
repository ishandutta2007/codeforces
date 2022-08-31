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
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, A, B, K;
char S[202020];

int main()
{
	scanf("%d%d%d%d%s", &N, &A, &B, &K, S);
	vector<pair<int, int> > seq;

	int st = -1;
	for (int i = 0; i <= N; ++i) {
		if (S[i] == '0') {
			if (st == -1) st = i;
		} else {
			if (st != -1) {
				if (i - st >= B) {
					seq.push_back({ st, i - st });
			//		printf("%d %d\n", st, i - st);
				}
				st = -1;
			}
		}
	}

	int mx = 0;
	for (int i = 0; i < seq.size(); ++i) mx += seq[i].second / B;

	vector<int> ans;
	for (int i = 0; i < seq.size(); ++i) {
		int lf = seq[i].first, len = seq[i].second;
		while (mx >= A && len >= B) {
			ans.push_back(lf + B);
			lf += B;
			len -= B;
			--mx;
		}
		if (mx < A) break;
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); ++i) printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));

	return 0;
}