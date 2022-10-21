#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n,d; cin >> n >> d;
        int Min=0,Max=n*(n-1)/2,now=0;
        for (int i=2;i<=n;++i){
            if ((1<<(now+1))==i) ++now;
            Min+=now;
        }
        if (d<Min||Max<d){cout << "NO" << '\n'; continue;}
        cout << "YES" << '\n';
        d=Max-d;
        vector<int> par(n),dep(n),deg(n,1);
        iota(par.begin(),par.end(),-1);
        iota(dep.begin(),dep.end(),0);
        deg[n-1]=0;
        for (int i=n-1;i>0;--i){
            if (!d) break;
            int m=n,node;
            for (int j=0;j<n;++j) if (j!=i&&deg[j]!=2){
                if (dep[i]-dep[j]-1==d){
                    node=j; break;
                }
                if (dep[j]+1<m) m=dep[j]+1,node=j;
            }
            --deg[par[i]]; ++deg[node];
            d-=dep[i]-dep[node]-1; dep[i]=dep[node]+1;
            par[i]=node;
        }
        for (int i=1;i<n;++i) cout << par[i]+1 << (i!=n-1?' ':'\n');
    }
}