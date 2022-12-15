#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 1e5 + 3;
const ll INF = 1e18;

int n, q;
ll a[N], pr[N];

struct Segment_Tree{
    ll mx[4 * N], mn[4 * N];

    void init(int i = 0, int l = 1, int r = n){
        if(l == r){
            mx[i] = mn[i] = pr[l];
            return;
        }
        int mid = (l + r) >> 1;
        init(2 * i + 1, l, mid);
        init(2 * i + 2, mid + 1, r);
        mx[i] = max(mx[2 * i + 1], mx[2 * i + 2]);
        mn[i] = min(mn[2 * i + 1], mn[2 * i + 2]);
    }

    ll get_max(int sl, int sr, int i = 0, int l = 1, int r = n){
        if(sr < l || r < sl) return -INF;
        if(sl <= l && r <= sr) return mx[i];
        int mid = (l + r) >> 1;
        return max(get_max(sl, sr, 2 * i + 1, l, mid), get_max(sl, sr, 2 * i + 2, mid + 1, r));
    }

    ll get_min(int sl, int sr, int i = 0, int l = 1, int r = n){
        if(sr < l || r < sl) return INF;
        if(sl <= l && r <= sr) return mn[i];
        int mid = (l + r) >> 1;
        return min(get_min(sl, sr, 2 * i + 1, l, mid), get_min(sl, sr, 2 * i + 2, mid + 1, r));
    }
} st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        a[i] -= x;
    }

    for(int i = 1; i <= n; ++i)
        pr[i] = pr[i - 1] + a[i];

    st.init();

    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        if(pr[l - 1] != pr[r]){
            cout << "-1\n";
            continue;
        }
        ll mx = st.get_max(l, r);
        if(mx > pr[l - 1]){
            cout << "-1\n";
            return 0;
        }
        cout << -(st.get_min(l, r) - pr[l - 1]) << "\n";
    }
}