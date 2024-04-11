#include <bits/stdc++.h>
using namespace std;

int n,a,b;
string ans;

void solve(){
    ans="";
    for (int i=0;i<n;++i){
        ans+=(char)('a'+i%b);
    }
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> a >> b;
        solve();
    }
}