#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <unordered_map>
#include <queue>
using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<li> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w", stdout);
#endif
    
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

int d[61][61][61];
int all[61][61];
struct race{
    int s,t,k, id;
    bool operator <(const race& b) const {
        return s<b.s;
    }
};
const int INF = 1e9;

race query[101010];
void solve(){
    int n,m,r;
    cin>>n>>m>>r;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<n;++k){
                cin>>d[i][j][k];
            }
        }
    }
    
    for(int v=0;v<m;++v){
        for (int k=0; k<n; ++k)
            for (int i=0; i<n; ++i)
                for (int j=0; j<n; ++j)
                    d[v][i][j] = min (d[v][i][j], d[v][i][k] + d[v][k][j]);
    }
    
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            all[i][j]  = INF;
            for(int k=0;k<m;++k){
                all[i][j]=min(all[i][j], d[k][i][j]);
            }
        }
    }
    
    
    for(int i=0;i<r;++i){
        cin>>query[i].s>>query[i].t>>query[i].k;
        --query[i].s;
        --query[i].t;
        ++query[i].k;
        query[i].k = min(60, query[i].k);
        query[i].id = i;
    }
    sort(query, query + r);
    int dp[61][60];
    int ans[101010];
    for(int i=0;i<r;++i){
        if(i==0 || query[i].s != query[i-1].s){
            int start = query[i].s;
            
            for(int i=0;i<=60;++i){
                for(int j=0;j<=60;++j){
                    dp[i][j] = INF;
                }
            }
            
            dp[0][start] = 0;
            for(int z=1;z<=60;++z){
                for(int cur=0;cur<n;++cur){
                    for(int prev=0;prev<n;++prev){
                        if(dp[z-1][prev]<INF)
                            dp[z][cur] = min(dp[z][cur],dp[z-1][prev] + all[prev][cur]);
                    }
                }
            }
            for(int v=0;v<n;++v){
                for(int t=1;t<=60;++t){
                    dp[t][v] = min(dp[t][v], dp[t-1][v]);
                }
            }
        }
        ans[query[i].id] = dp[query[i].k][query[i].t];
    }
    
    for(int i=0;i<r;++i){
        cout<<ans[i]<<'\n';
    }
}