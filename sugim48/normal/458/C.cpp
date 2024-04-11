#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> ll_i;
struct edge { int u, v; ll w; };

vector<int> v[100001], w[100000];

int main() {
	int n; scanf("%d", &n);
	int num = n, bsum = 0;
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d%d", &a, &b);
		if (a == 0) ;
		else {
			bsum += b;
			v[a].push_back(b);
		}
	}
	for (int a = 1; a <= 100000; a++) {
		sort(v[a].begin(), v[a].end(), greater<int>());
		for (int i = 0; i < v[a].size(); i++) w[i].push_back(v[a][i]);
	}
	int ans = INT_MAX, bext = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; ; i++) {
		int cost = bsum;
		if (num + pq.size() <= i) break;
		while (num <= i) {
			num++;
			bext += pq.top(); pq.pop();
		}
		cost += bext;
		ans = min(ans, cost);
		if (w[i].size() == 0) break;
		num -= w[i].size();
		for (int k = 0; k < w[i].size(); k++) {
			bsum -= w[i][k];
			pq.push(w[i][k]);
		}
	}
	printf("%d\n", ans);
}