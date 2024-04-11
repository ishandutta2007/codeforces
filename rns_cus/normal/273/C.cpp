#include <bits/stdc++.h>

using namespace std;

#define N 300300

typedef pair<int, int> pii;

set <pii> s[2];
set <pii> :: iterator it;
int n, m, col[N], d[N];
int v[N][3];

void update(int id, int x, int val) {
	int dd = 0;
	for(int i = 0; i < d[x]; i ++) {
 		if(col[v[x][i]] == id) dd ++;
	}
	s[id].erase(pii(-dd, x));
	s[id].insert(pii(-dd-val, x));
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m ;i ++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x][d[x] ++] = y;
		v[y][d[y] ++] = x;
	}
	for(int i = 1; i <= n; i ++) {
		s[0].insert(pii(-d[i], i));
	}
	while(1) {
		it = s[0].begin();
		if(it != s[0].end() && it -> first <= -2) {
			int i = it -> second, dd = it -> first;
			for(int j = 0; j < d[i]; j ++) {
				if(!col[v[i][j]]) update(0, v[i][j], -1);
				else update(1, v[i][j], 1);
			}
			s[0].erase(pii(dd, i));
			s[1].insert(pii(-d[i] - dd, i));
			col[i] = 1;
			continue;
		}
		it = s[1].begin();
		if(it != s[1].end() && it -> first <= -2) {
			int i = it -> second, dd = it -> first;
			for(int j = 0; j < d[i]; j ++) {
				if(col[v[i][j]]) update(1, v[i][j], -1);
				else update(0, v[i][j], 1);
			}
			s[1].erase(pii(dd, i));
			s[0].insert(pii(-d[i] - dd, i));
			col[i] = 0;
			continue;
		} else break;
	}
	for(int i = 1 ;i <= n; i ++) printf("%d", col[i]); puts("");
	return 0;
}