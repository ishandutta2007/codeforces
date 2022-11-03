#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

int n;
int pts[1024][2];
int father[1024];

int GetF(int a) {
	return (father[a] == a ? a : GetF(father[a]));
}

int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d%d", &pts[i][0], &pts[i][1]);
	for (int i = 0; i<n; i++) father[i] = i;

	for (int i = 0; i<n; i++)
		for (int j = i+1; j<n; j++)
			if (pts[i][0] == pts[j][0] || pts[i][1] == pts[j][1])
				if (GetF(i) != GetF(j))
				father[GetF(i)] = GetF(j);

	set<int> q;
	for (int i = 0; i<n; i++) q.insert(GetF(i));
	printf("%d\n", q.size() - 1);
				
	return 0;
}