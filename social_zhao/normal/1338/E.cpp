#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 8005, rev[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
int n;
long long ans = 0;
int edge[N][N], ind[N], oud[N];
char s[N];
int bin[N], vis[N], mn[N];

int mp(char c) { if(isdigit(c)) return c - '0'; else return 10 + c - 'A'; }
void add(int u, int v) { edge[u][v] = 1, ++oud[u], ++ind[v]; }

main() {
	n = get();
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j = 1; j * 4 <= n; j++) {
			int now = rev[mp(s[j])];
			for(int k = 0; k < 4; k++) if(now >> k & 1) add(i, 4 * (j - 1) + k + 1); 
		}
	}
	for(int i = 1; i <= n; i++) bin[i] = i;
	sort(bin + 1, bin + 1 + n, [](int x, int y) { return oud[x] < oud[y]; });
	int top = n;
	while(top && oud[bin[top]] == top - 1) 
		ans += top - 1 + 1ll * n * 614 * (top - 1), vis[bin[top]] = 1, --top;
	for(int i = 1; i <= n; i++) if(!vis[i])
		for(int j = 1; j <= n; j++) if(!vis[j])
			if(edge[i][j]) {
				if(!mn[i] || edge[mn[i]][j]) mn[i] = j;
			}
	
	int dis1 = top * (top - 1) / 2, dis2 = 0, dis3;
	for(int i = 1; i <= n; i++) if(!vis[i])
		for(int j = 1; j <= n; j++) if(!vis[j])
			if(edge[j][i] && edge[mn[i]][j]) dis2++;
	dis3 = top * (top - 1) / 2 - dis2;
	ans += dis1 + dis2 * 2 + dis3 * 3;
	
	cout << ans << endl;
	return 0;
}