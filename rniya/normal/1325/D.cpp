#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll u,v; cin >> u >> v;
    if (v<u||(v-u)&1){cout << -1 << '\n'; return 0;}
    if (u==0&&v==0){cout << 0 << '\n'; return 0;}
    if (u==v){cout << 1 << '\n' << u << '\n'; return 0;}
    ll w=(v-u)>>1LL;
    if (!(w&u)){
        cout << 2 << '\n';
        cout << u+w << ' ' << w << '\n';
        return 0;
    }
    cout << 3 << '\n';
    cout << u << ' ' << w << ' ' << w << '\n';
}