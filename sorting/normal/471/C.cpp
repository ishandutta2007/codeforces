#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

ll t(ll f){
    return 3ll * f * (f + 1) / 2 - f;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    ll rem = (3 - n % 3);

    const ll INF = 1e8;
    ll l = -1, r = INF;
    while(l != r){
        ll mid = (l + r + 1) >> 1;
        if(t(3 * mid + rem) > n)
            r = mid - 1;
        else
            l = mid;
    }

    cout << l + 1 << "\n";
}