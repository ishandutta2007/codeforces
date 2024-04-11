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

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
int mind;

bool ask(int n)
{
	if (true) {
		printf("%d\n", n);
		fflush(stdout);
		char in[5];
		scanf("%s", in);
		return in[0] == 'y';
	}
	return mind % n == 0;
}

bool solve()
{
	int n_yes = 0;
	for (int a : primes) {
		bool f = ask(a);
		if (f) {
			++n_yes;
			if (a < 10 && ask(a * a)) ++n_yes;
		}
	}

	return n_yes <= 1;
}

int main()
{
	if (solve()) puts("prime");
	else puts("composite");
	/*
	for (int i = 2; i <= 100; ++i) {
		mind = i;
		bool a = solve();
		bool b = true;
		for (int j = 2; j < i; ++j) if (i % j == 0) b = false;

		if (a != b) {
			printf("%d %d %d\n", i, a, b);
		}
	}
	*/
	return 0;
}