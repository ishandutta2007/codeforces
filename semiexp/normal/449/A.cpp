#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000009
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)
typedef long long i64;

i64 N, M, K;

i64 solve(i64 X)
{
	if (X >= N || (K-X) >= M) return -1;
	if(X < 0 || K-X < 0) return -1;

	return (N/(X+1)) * (M/(K-X+1));
}

int main()
{
	cin >> N >> M >> K;

	if (N+M-2 < K) {
		puts("-1");
		return 0;
	}

	i64 ret = 0;
	for(int i=0;i<=100000;i++) {
		ret = max(ret, solve(i));
		if(i>0) ret = max(ret, solve(min(K, N / i - 1)));
	}

	cout << ret << endl;
	return 0;
}