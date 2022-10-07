#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l[100009],s[100009],p[100009];
main(){
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        cin >> l[i];
        s[i] = s[i-1] + l[i];
        if(l[i] + i - 1 > n){
            cout << -1 << endl;
            return 0;
        }
    }
    if(l[m] + m - 1 > n || s[m] < n){
        cout << -1 << endl;
        return 0;
    }
    p[m] = n - l[m] + 1;
    ll x = p[m];
    for(ll i = m-1; i >= 1; i--){
        p[i] = max(i, x - l[i]);
        x = p[i];

    }
    for(ll i=1 ;i <= m; i++)
        cout<<p[i]<<" ";
    cout<<endl;
}