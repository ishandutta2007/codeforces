#include <bits/stdc++.h>

using namespace std;

#define N 4040
vector <int> v[N];

int n, a[N], b[N], bin[N];
int m;

int calc(int x, int y) {
	int id;
	if(v[x][0] > v[y][0]) id = 1; else id = 0;
	int cur = min(v[x][0], v[y][0]);
	int sx = (int)v[x].size(), i = 0;
	int sy = (int)v[y].size(), j = 0, rt = 1;
	if(id) j = 1; else i = 1;
	while(1) {
		if(id) {
			while(i < sx && v[x][i] < cur) i ++;
			if(i == sx) break;
			cur = v[x][i];
			rt ++;
		} else {
			while(j < sy && v[y][j] < cur) j ++;
			if(j == sy) break;
			cur = v[y][j];
			rt ++;
		}
		id = 1 - id;
	}
	return rt;
}

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d" , a + i);
		b[i - 1] = a[i];
	}
	m = n;
	sort(b, b + m);
	m = unique(b, b + m) - b;
	for(int i = 1; i <= n; i ++) {
		a[i] = lower_bound(b, b + m, a[i]) - b;
		v[a[i]].push_back(i);
	}
	int mx = 0;
	for(int i = 0; i < m; i ++) {
		int sz = (int)v[i].size();
		if(mx < sz) mx = sz;
	}
	for(int i = 0; i < m; i ++) for(int j = i + 1; j < m; j ++) {
		int tp = calc(i, j);
		if(mx < tp) mx = tp;
	}
	printf("%d\n", mx);
	return 0;
}