#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int N = 3e5 + 3;
const ll INF = 1e18;

int n;
ll a[N];

struct SegmentTree{
    struct Node{
        ll mn, cnt;

        Node(){}
        Node(ll x){
            mn = x;
            cnt = 1;
        }

        friend Node merge(const Node &l, const Node &r){
            Node ret;
            ret.mn = min(l.mn, r.mn);
            ret.cnt = 0;
            if(l.mn == ret.mn) ret.cnt += l.cnt;
            if(r.mn == ret.mn) ret.cnt += r.cnt;
            return ret;
        }
    } nd[4 * N];
    ll lp[4 * N];
    bool odd;

    void init2(int i, int l, int r){
        lp[i] = 0;
        if(l == r){
            if((l & 1) == odd){
                nd[i] = Node(a[l]);
            }
            else{
                nd[i] = Node(INF);
            }
            return;
        }
        int mid = (l + r) >> 1;
        init2(2 * i + 1, l, mid);
        init2(2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
    }

    void init(bool odd){
        this->odd = odd;
        init2(0, 1, n);
    }

    void push(int i, int l, int r){
        if(!lp[i]) return;
        if(l != r){
            lp[2 * i + 1] += lp[i];
            lp[2 * i + 2] += lp[i];
        }
        nd[i].mn += lp[i];
        lp[i] = 0;
    }

    void update(int sl, int sr, ll d, int i = 0, int l = 1, int r = n){
        push(i, l, r);
        if(sr < l || r < sl) return;
        if(sl <= l && r <= sr){
            lp[i] += d;
            push(i, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(sl, sr, d, 2 * i + 1, l, mid);
        update(sl, sr, d, 2 * i + 2, mid + 1, r);
        nd[i] = merge(nd[2 * i + 1], nd[2 * i + 2]);
    }

    int get_smaller_than_0(int sl, int sr, int i = 0, int l = 1, int r = n){
        push(i, l, r);
        if(sr < l || r < sl) return n;
        if(nd[i].mn >= 0) return n;
        if(l == r) return l - 1;

        int mid = (l + r) >> 1;
        int l_ans = get_smaller_than_0(sl, sr, 2 * i + 1, l, mid);
        if(l_ans != n) return l_ans;
        return get_smaller_than_0(sl, sr, 2 * i + 2, mid + 1, r);
    }

    ll get_0_count(int sl, int sr, int i = 0, int l = 1, int r = n){
        push(i, l, r);
        if(sr < l || r < sl) return 0;
        if(sl <= l && r <= sr){
            if(nd[i].mn) return 0;
            return nd[i].cnt;
        }

        int mid = (l + r) >> 1;
        return get_0_count(sl, sr, 2 * i + 1, l, mid) + get_0_count(sl, sr, 2 * i + 2, mid + 1, r);
    }
} st[2];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    st[0].init(0);
    st[1].init(1);

    ll ans = 0;
    for(int i = n; i >= 1; --i){
        if(i & 1){
            st[0].update(i + 1, n, -a[i]);
            st[1].update(i + 1, n, a[i]);
        }
        else{
            st[0].update(i + 1, n, a[i]);
            st[1].update(i + 1, n, -a[i]);
        }

        int r = min(st[0].get_smaller_than_0(i + 1, n), st[1].get_smaller_than_0(i + 1, n));
        ans += st[0].get_0_count(i, r) + st[1].get_0_count(i, r);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
        solve();
}