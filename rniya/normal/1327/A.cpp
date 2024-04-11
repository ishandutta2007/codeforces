#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        ll n,k; cin >> n >> k;
        if (k*k<=n&&!((n-k)&1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}