#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 2e5 + 3;
const ll INF = 3e18;

ll n;
ll a[N], sum = 0;

void solve(){
    cin >> n;
    sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);

    if(sum + a[n - 1] * (n - 2) < 0){
        cout << "INF\n";
        return;
    }
    if(sum + a[0] * (n - 2) > 0){
        cout << "INF\n";
        return;
    }

    ll cnt_t = 0, score = 0;
    for(int i = 1; i < n; ++i){
        cnt_t += (a[0] + a[i]);
        score += a[0] * a[i];
    }

    ll mx = -INF;
    check_max(mx, score + cnt_t * -a[0]);
    for(int i = 1; i < n; ++i){
        cnt_t -= (a[0] + a[i]);
        score -= a[0] * a[i];
        cnt_t += a[n - 1] + a[i];
        score += a[n - 1] * a[i];
        check_max(mx, score + cnt_t * -a[i]);
    }
    cout << mx << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }
}