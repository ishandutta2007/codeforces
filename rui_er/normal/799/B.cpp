//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int n, m, p[N], a[N], b[N], vis[N], cnt[4];
vector<int> c[4];
bool cmp(int a, int b) {return p[a] < p[b];}

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &p[i]);
	for(int i=1;i<=n;i++) {scanf("%d", &a[i]); c[a[i]].push_back(i);}
	for(int i=1;i<=n;i++) {scanf("%d", &b[i]); if(a[i] != b[i]) c[b[i]].push_back(i);}
	for(int i=1;i<=3;i++) sort(c[i].begin(), c[i].end(), cmp);
	scanf("%d", &m);
	while(m--) {
		int x;
		scanf("%d", &x);
		bool _ = true;
		for(int i=cnt[x];i<c[x].size();i++) {
			if(!vis[c[x][i]]) {
				printf("%d ", p[c[x][i]]);
				vis[c[x][i]] = 1;
				cnt[x] = i;
				_ = false;
				break;
			}
		}
		if(_) printf("-1 ");
	}
	return 0;
}