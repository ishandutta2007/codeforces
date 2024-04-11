#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

vector<int> diviisor(int n){
    vector<int> res;
    for (int i=1;i*i<=n;++i) if (n%i==0){
        res.emplace_back(i);
        if (i!=n/i) res.emplace_back(n/i);
    }
    return res;
}

int T,n,now,ans,k;
int p[MAX_N],c[MAX_N];
vector<int> visited(MAX_N),cycle,divi;

void solve(){
    ans=n;
    fill(visited.begin(),visited.begin()+n,0);
    for (int i=0;i<n;++i) if (!visited[i]){
        cycle.clear();
        now=i;
        while(1){
            visited[now]=1;
            cycle.emplace_back(now);
            now=p[now];
            if (now==i) break;
        }
        k=cycle.size(); ans=min(ans,k);
        for (int u:diviisor(k)){
            for (int s=0;s<u;++s){
                for (int t=s,j=0;j<k/u;(t+=u)%=k,++j){
                    if (c[cycle[t]]!=c[cycle[s]]) break;
                    if (j==k/u-1) ans=min(ans,u);
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    for (;T--;){
        cin >> n;
        for (int i=0;i<n;++i) cin >> p[i],--p[i];
        for (int i=0;i<n;++i) cin >> c[i];
        solve();
    }
}