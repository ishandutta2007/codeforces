#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N=4010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,K; cin >> n >> m >> K;
    vector<int> l(m),r(m);
    for (int i=0;i<m;++i) cin >> l[i] >> r[i],--l[i];

    auto solve=[&](int x){
        ll res=0;
        vector<int> imos(MAX_N,0);
        for (int i=0;i<m;++i){
            int score=max(0,min(x+K,r[i])-max(x,l[i]));
            res+=score;
            int Max=min(K,r[i]-l[i]);
            if (score==Max) continue;
            ++imos[l[i]+score+1]; --imos[l[i]+Max+1];
            --imos[r[i]+K-Max+1]; ++imos[r[i]+K-score+1];
        }
        for (int i=0;i<MAX_N-1;++i) imos[i+1]+=imos[i];
        for (int i=0;i<MAX_N-1;++i) imos[i+1]+=imos[i];
        int ret=0;
        for (int i=0;i<n;++i) ret=max(ret,imos[i]);
        return res+ret;
    };

    ll ans=0;
    for (int i=0;i+K<=n;++i) ans=max(ans,solve(i));

    cout << ans << '\n';
}