#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

char s[105];
vector <int> g[105];
int a[sz],d[105][105],cut[sz];
queue <int> q;

void bfs(int r)
{
    while(!q.empty()) {
        int x=q.front();
        for(int i=0; i<g[x].size(); i++) {
            int y=g[x][i];
            if(d[r][y]<0) {
                d[r][y]=d[r][x]+1;
                q.push(y);
            }
        }
        q.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        for(int j=0; j<n; j++) {
            if(s[j]=='1') {
                g[i+1].push_back(j+1);
            }
        }
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++) scanf("%d", &a[i]);

    memset(d, -1, sizeof(d));
    for(int i=1; i<=n; i++) {
        q.push(i);
        d[i][i]=0;
        bfs(i);
    }

    vector <int> ans;
    ans.push_back(0);
    for(int i=1; i<m-1; i++) {
        int x=ans.back();
        int y=i+1;

        int u=a[x], v=a[y];
        if(d[u][v]<y-x) ans.push_back(i);
    }
    ans.push_back(m-1);

    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++) printf("%d ", a[ans[i]]);
}