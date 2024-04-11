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
int N, A[101010];

int odds[101010], evens[101010];
int main()
{
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%d", A + i);

		for (int i = 0; i <= 100000; ++i) {
			odds[i] = evens[i] = 0;
		}
		for (int i = 0; i < N; ++i) {
			if (i % 2 == 0) evens[A[i]]++;
			else odds[A[i]]++;
		}
		sort(A, A + N);
		for (int i = 0; i < N; ++i) {
			if (i % 2 == 0) evens[A[i]]--;
			else odds[A[i]]--;
		}
		bool flg = true;
		for (int i = 0; i <= 100000; ++i) {
			if (evens[i] != 0 || odds[i] != 0) flg = false;
		}
		puts(flg ? "YES" : "NO");
	}
	return 0;
}