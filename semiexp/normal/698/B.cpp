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

int N, A[202020];
int visited[202020];
vector<vector<int> > cycs;

void found_cyc(int p)
{
	vector<int> a;
	while (true) {
		if (visited[p] == 2) break;
		a.push_back(p);
		visited[p] = 2;
		p = A[p];
	}
	cycs.push_back(a);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", A + i); --A[i];
		visited[i] = 0;
	}

	for (int i = 0; i < N; ++i) if (visited[i] == 0) {
		int p = i;
		for (;;) {
			if (visited[p] == 0) {
				visited[p] = 1;
			} else if (visited[p] == 1) {
				found_cyc(p);
				break;
			} else {
				break;
			}
			p = A[p];
		}
		p = i;
		for (;;) {
			if (visited[p] == 1) visited[p] = 2;
			else break;
			p = A[p];
		}
	}

	int cyc1 = -1;
	for (int i = 0; i < cycs.size(); ++i) if (cycs[i].size() == 1) cyc1 = i;

	if (cyc1 == -1) cyc1 = 0;

	int rt = cycs[cyc1][0];

	int chg = 0;
	for (int i = 0; i < cycs.size(); ++i) {
		int p = cycs[i][0];
		if (A[p] != rt) ++chg;
		A[p] = rt;
	}

	printf("%d\n", chg);
	for (int i = 0; i < N; ++i) printf("%d%c", A[i] + 1, (i == N - 1) ? '\n' : ' ');
	return 0;
}