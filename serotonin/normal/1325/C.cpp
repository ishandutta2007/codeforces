#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

int ans[sz];
vector <pii> g[sz];

int main()
{
    int t=1;
    while(t--) {
        int n;
        scanf("%d", &n);

        for(int i=1; i<n; i++) {
            int x,y;
            scanf("%d %d", &x, &y);
            g[x].push_back({y,i});
            g[y].push_back({x,i});
        }

        if(n==2) {
            puts("0");
            continue;
        }

        int who=0;
        for(int i=1; i<=n; i++) if(g[i].size()>2) who=i;

        if(!who) {
            for(int i=1; i<n; i++) printf("%d\n", i-1);
        }
        else {
            int k=0;
            for(auto p : g[who]) ans[p.y]=++k;
            for(int i=1; i<n; i++) if(!ans[i]) ans[i]=++k;

            for(int i=1; i<n; i++) printf("%d\n", ans[i]-1);
        }
    }
}