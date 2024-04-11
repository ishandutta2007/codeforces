#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=85, inf=1e9;

typedef pair <int,int> pii;
#define x first
#define y second

bitset <sz> vis;
vector <pii> d[sz][sz];

int n, m, a[sz][sz], ans=inf;

inline void fnc(int now[], int z)
{
    int dis[6][5], r[5][5];
    for(int i=0; i<z; i++) {
        for(int k=0; k<=m; k++) {
            dis[i][k]=inf;
        }
        vis[now[i]]=1;
    }
    dis[0][0]=0;

    for(int i=0; i<z; i++) {
        for(int j=0; j<z; j++) {
            r[i][j]=inf;
            int u=now[i], v=now[j];
            for(auto p : d[u][v]) {
                if(!vis[p.y]) {
                    r[i][j]=p.x;
                    break;
                }
            }
        }
    }

    for(int k=1; k<=m; k++) {
        for(int i=0; i<z; i++) {
            for(int j=0; j<z; j++) {
                dis[j][k]=min(dis[j][k], dis[i][k-1]+r[i][j]);
            }
        }
    }

    for(int i=0; i<z; i++) vis[now[i]]=0;

    ans=min(ans, dis[0][m]);
}

void solve()
{
    int ara[5], c = 1;
    ara[0]=1, fnc(ara,c);
    for(int i=2; i<=n; i++) {
        ara[1]=i, fnc(ara, 2);
        for(int j=i+1; j<=n; j++) {
            ara[2]=j, fnc(ara, 3);
            for(int k=j+1; k<=n; k++) {
                ara[3]=k, fnc(ara, 4);
                for(int l=k+1; l<=n; l++) {
                    ara[4]=l, fnc(ara, 5);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    m>>=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            vector <pii> now;
            for(int k=2; k<=n; k++) {
                if(k==i || k==j) continue;
                now.push_back({a[i][k]+a[k][j], k});
            }
            sort(now.begin(), now.end());
            for(int k=0; k<now.size(); k++) {
                d[i][j].push_back(now[k]);
                if(k==4) break;
            }
        }
    }

    solve();

    printf("%d\n", ans);
}