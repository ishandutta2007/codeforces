#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(auto &x: a)
        cin >> x;

    const ll INF = 1e18;

    ll ans = INF;
    for(int i = 0; i < n; ++i){
        ll cand = 0;
        ll curr = 0;
        for(int j = i - 1; j >= 0; --j){
            ++curr;
            ll t = curr / a[j] + !!(curr % a[j]);
            cand += t;
            curr = t * a[j];
        }
        curr = 0;
        for(int j = i + 1; j < n; ++j){
            ++curr;
            ll t = curr / a[j] + !!(curr % a[j]);
            cand += t;
            curr = t * a[j];
        }
        check_min(ans, cand);
    }
    cout << ans;
}