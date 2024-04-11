#include <bits/stdc++.h>
using namespace std;

int t;
long long d,m,po,ans;

void solve(){
    po=ans=1;
    while((po<<1LL)<=d){
        (ans*=po%m+1)%=m;
        if ((po<<1LL)<=d) po<<=1LL;
    }
    (ans*=(d-po)%m+2)%m;
    cout << (ans+m-1)%m << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    for (;t--;){
        cin >> d >> m;
        solve();
    }
}