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
priority_queue<int> seq;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int x;
		scanf("%d", &x);
		seq.push(-x);
	}

	int ret = 0;
	while (seq.size() >= 2) {
		int p = seq.top(); seq.pop();
		int q = seq.top(); seq.pop();

		if (p == q) {
			seq.push(q - 1);
		} else {
			++ret;
			seq.push(q);
		}
	}
	printf("%d\n", ret + 1);
	return 0;
}