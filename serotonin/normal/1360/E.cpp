#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

char s[sz][sz];
bool vis[sz][sz];

void dfs(int x, int y)
{
    if(vis[x][y]) return;
    vis[x][y] = 1;
    if(x && s[x-1][y] == '1') dfs(x-1, y);
    if(y && s[x][y-1] == '1') dfs(x, y-1);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%s", s[i]);

        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++) {
            if(s[n-1][i] == '1') dfs(n-1, i);
            if(s[i][n-1] == '1') dfs(i, n-1);
        }

        bool no = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(s[i][j] == '1' && !vis[i][j]) no = 1;
            }
        }

        if(no) puts("NO");
        else puts("YES");
    }
}