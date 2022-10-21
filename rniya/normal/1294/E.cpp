#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin >> a[i][j];
    ll ans=0;
    vector<ll> sum(n);
    for (int j=0;j<m;++j){
        fill(sum.begin(),sum.end(),0);
        for (int i=0;i<n;++i) if (a[i][j]%m+(a[i][j]%m==0?m:0)==j+1){
            int col=(a[i][j]-j-1)/m;
            if (n<=col) continue;
            ++sum[(i+n-col)%n];
        }
        ll cnt=INF;
        for (int i=0;i<n;++i) cnt=min(cnt,n-sum[i]+i);
        ans+=cnt;
    }
    cout << ans << '\n';
}