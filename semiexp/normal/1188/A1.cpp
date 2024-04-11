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

int N;
vector<int> graph[101010];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 0; i < N; ++i) {
		if (graph[i].size() == 2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}