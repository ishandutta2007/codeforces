#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 2e5 + 3;

ll n, m, a[N];
vector<ll> b[N];
vector<array<ll, 2>> upd_log;
ll sum[N];

struct SegmentTree{
    struct Node{
        ll mn, sum;
    
        Node(){}
        Node(ll val){
            mn = val;
            sum = val;
        }


        friend Node merge(const Node &l, const Node &r){
            Node res;
            res.mn = min(r.mn, l.mn + r.sum);
            res.sum = l.sum + r.sum;
            return res;
        }
    } nd[4 * N];

    void update(ll s, ll val, ll i = 0, ll l = 0, ll r = N - 1){
        if(s < l || r < s) return;
        if(l == r){
            nd[i].sum = nd[i].mn += val;
            return;
        }

        ll mid = (l + r) >> 1;
        update(s, val, 2 * i + 1, l, mid);
        update(s, val, 2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
    }

    ll query(ll i = 0, ll l = 0, ll r = N - 1){
        return nd[i].mn;
    }
} st;

void update_fraction(ll up, ll down, ll val){
    st.update(up / down + !!(up % down), val);
}

void solve(){
    cin >> n >> m;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        update_fraction(a[i], 1, 1);
    }
    for(ll i = 0; i < m; ++i){
        ll k;
        cin >> k;
        b[i] = vector<ll>(k);
        sum[i] = 0;
        for(ll j = 0; j < k; ++j){
            cin >> b[i][j];
            sum[i] += b[i][j];
        }
        update_fraction(sum[i], k, -1);
    }

    string ans = "";
    for(ll i = 0; i < m; ++i){
        for(ll j = 0; j < b[i].size(); ++j){
            update_fraction(sum[i], b[i].size(), 1);
            update_fraction(sum[i] - b[i][j], b[i].size() - 1, -1);

            ans += (char)('0' + (st.query() >= 0));

            update_fraction(sum[i], b[i].size(), -1);
            update_fraction(sum[i] - b[i][j], b[i].size() - 1, 1);
        }
    }

    for(ll i = 0; i < n; ++i)
        update_fraction(a[i], 1, -1);
    for(ll i = 0; i < m; ++i)
        update_fraction(sum[i], b[i].size(), 1);

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
        solve();
}