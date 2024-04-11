#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, k;
char s[N];
int a[N], src, tar;
bool vis[N];

bool bfs() {
    queue <int> q;
	q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
		int x = q.front(); q.pop();
        if (x + k < n && a[x+k] == 1 && !vis[x+k]) {
            vis[x+k] = 1; q.push(x+k);
        }
        if (x - k >= 0 && a[x-k] == 1 && !vis[x-k]) {
            vis[x-k] = 1; q.push(x - k);
        }
    }
    if (vis[tar]) return 1;
    return 0;
}

int main() {
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) {
        if (s[i] == '.') a[i] = 1;
        else if (s[i] == '#') a[i] = 2;
        else if (s[i] == 'G') src = i, a[i] = 1;
        else if (s[i] == 'T') tar = i, a[i] = 1;
	}
    bool f = bfs();
    if (f) puts("YES");
    else puts("NO");
	return 0;
}