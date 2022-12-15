#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

ll calc(ll x, int var){
    if(!var) return x * x;
    if(var == 1) return x * (x + 1);
    return x * (x + 2);
}

ll cnt(ll x, int var){
    ll l = 0, r = 1e9;
    while(l != r){
        ll mid = (l + r + 1) >> 1;
        if(calc(mid, var) <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

ll f(ll x){
    if(!x) return 0;
    ll ans = 0;
    for(int i = 0; i < 3; ++i)
        ans += cnt(x, i);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << "\n";
    }
}