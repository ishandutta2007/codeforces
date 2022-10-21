#include <bits/stdc++.h>
using namespace std;
const int MAX_N=85,INF=1e9;

int n,K,c[MAX_N][MAX_N],ans=INF;
vector<pair<int,int>> cand[MAX_N][MAX_N];
vector<int> route;

void dfs(int v){
    if (v==K/2){
        route.emplace_back(0);
        int sum=0;
        for (int i=0;i<v;++i){
            int u=route[i],v=route[i+1];
            for (auto e:cand[u][v]){
                int w=e.second,ok=0;
                for (int ng:route){
                    ok|=(ng==w);
                }
                if (!ok){sum+=e.first; break;}
            }
            if (ans<sum) break;
        }
        route.pop_back();
        ans=min(ans,sum);
        return;
    }
    for (int i=0;i<n;++i){
        route.emplace_back(i);
        dfs(v+1);
        route.pop_back();
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> K;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            cin >> c[i][j];
        }
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            for (int k=0;k<n;++k){
                if (i==k||j==k) continue;
                cand[i][j].emplace_back(c[i][k]+c[k][j],k);
            }
            cand[i][j].emplace_back(INF,n);
            sort(cand[i][j].begin(),cand[i][j].end());
        }
    }
    route.emplace_back(0);
    dfs(1);
    cout << ans << '\n';
}