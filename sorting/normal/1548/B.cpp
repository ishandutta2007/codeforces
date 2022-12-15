#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 2e5 + 3;

int n;
ll a[N];

ll gcd(ll a, ll b){
    while(b){
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}

struct SegmentTree{
    ll x[4 * N];

    void init(int i = 0, int l = 0, int r = n - 1){
        if(l == r){
            x[i] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        init(2 * i + 1, l, mid);
        init(2 * i + 2, mid + 1, r);
        x[i] = gcd(x[2 * i + 1], x[2 * i + 2]);
    }

    ll query(int sl, int sr, int i = 0, int l = 0, int r = n - 1){
        if(sr < l || r < sl) return 0;
        if(sl <= l && r <= sr) return x[i];
        int mid = (l + r) >> 1;
        return gcd(query(sl, sr, 2 * i + 1, l, mid), query(sl, sr, 2 * i + 2, mid + 1, r));
    }
} st;

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == 1){
        cout << "1\n";
        return;
    }
    for(int i = 0; i < n - 1; ++i)
        a[i] = abs(a[i] - a[i + 1]);

    st.init();

    int l = 0, ans = 1;
    for(int r = 0; r < n - 1; ++r){
        while(l <= r && st.query(l, r) == 1)
            ++l;
        check_max(ans, r - l + 2);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) solve();
}