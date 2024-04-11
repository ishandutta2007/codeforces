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

int N, K;
char in[10000];

bool valid(string &s, char c)
{
	if (s[s.size() - 1] == c) return false;
	if (s.size() >= 2 && s[s.size() - 2] == c) return false;
	return true;
}

int main()
{
	scanf("%d%d%s", &N, &K, in);

	string ret = "~";

	for (int i = 0; i < N; ++i) {
		// change at in[i]
		for (char j = in[i] + 1; j < 'a' + K; ++j) {
			if (i > 0 && j == in[i - 1]) continue;
			if (i > 1 && j == in[i - 2]) continue;

			string tmp;
			for (int k = 0; k < i; ++k) tmp.push_back(in[k]);
			tmp.push_back(j);
			for (int k = i + 1; k < N; ++k) {
				if (valid(tmp, 'a')) {
					tmp.push_back('a');
				} else if (K >= 2 && valid(tmp, 'b')) {
					tmp.push_back('b');
				} else if (K >= 3 && valid(tmp, 'c')) {
					tmp.push_back('c');
				} else goto nex;
			}

			ret = min(ret, tmp);

			break;
		nex:
			continue;
		}

		// keep in[i]
		if (i > 0 && in[i] == in[i - 1]) break;
		if (i > 1 && in[i] == in[i - 2]) break;
	}

	if (ret[0] == '~') puts("NO");
	else puts(ret.c_str());

	return 0;
}