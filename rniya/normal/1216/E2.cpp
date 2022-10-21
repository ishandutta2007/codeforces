#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
ll po[10];

ll sum(ll n){
    string s=to_string(n);
    int d=s.size();
    ll res=0;
    for (int i=1;i<=d;++i){
        if (i<d) res+=9*po[i-1]*i;
        else res+=(n-po[d-1]+1)*d;
    }
    return res;
}

ll allsum(ll n){
    string s=to_string(n);
    int d=s.size();
    ll res=0;
    for (int i=1;i<=d;++i){
        if (i<d){
            res+=i*(po[i]-po[i-1]+1)*(po[i]-po[i-1])/2;
            res+=sum(po[i-1]-1)*(po[i]-po[i-1]);
        } else {
            res+=i*(n-po[i-1]+2)*(n-po[i-1]+1)/2;
            res+=sum(po[i-1]-1)*(n-po[i-1]+1);
        }
    }
    return res;
}

void solve(){
    ll lb=0,ub=1e9;
    while(ub-lb>1){
        ll mid=(ub+lb)>>1LL;
        (allsum(mid)<=k?lb:ub)=mid;
    }
    k-=allsum(lb);
    lb=0,ub=1e9;
    while(ub-lb>1){
        ll mid=(ub+lb)>>1LL;
        (sum(mid)<=k?lb:ub)=mid;
    }
    k-=sum(lb);
    string ans=to_string(ub);
    cout << ans[k] << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    po[0]=1;
    for (int i=0;i<9;++i) po[i+1]=po[i]*10;
    int q; cin >> q;
    for (;q--;){
        cin >> k; --k;
        solve();
    }
}