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

int TC;
int N;
char S[202020];

int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d%s", &N, S);

		string A, B;
		int a = 0, b = 0;

		int n_ones = 0;
		for (int i = 0; i < N; ++i) if (S[i] == '1') ++n_ones;

		int n_zeros = 0;

		if (n_ones % 2 == 1) {
			goto fail;
		}
		n_ones /= 2;
		for (int i = 0; i < N; ++i) {
			if (S[i] == '1') {
				if (n_ones-- > 0) {
					A.push_back('(');
					B.push_back('(');
					++a;
					++b;
				} else {
					if (a == 0 || b == 0) goto fail;
					--a;
					--b;
					A.push_back(')');
					B.push_back(')');
				}
			} else {
				++n_zeros;
				if (n_zeros % 2 == 0) {
					if (b == 0) goto fail;
					++a; --b;
					A.push_back('(');
					B.push_back(')');
				} else {
					if (a == 0) goto fail;
					--a; ++b;
					A.push_back(')');
					B.push_back('(');
				}
			}
		}

		puts("YES");
		puts(A.c_str());
		puts(B.c_str());
		continue;

		fail:
		puts("NO");
	}
	return 0;
}