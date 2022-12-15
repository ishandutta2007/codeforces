#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 2e5 + 3;

struct Segment_Tree{
    struct Node{
        ll mn, mx, sum, lp, cnt;

        Node(){}

        friend Node merge(const Node &lvalue, const Node &rvalue){
            Node ret;
            ret.mx = lvalue.mx;
            ret.mn = rvalue.mn;
            ret.sum = lvalue.sum + rvalue.sum;
            ret.lp = 0;
            ret.cnt = lvalue.cnt + rvalue.cnt;
            return ret;
        }
    };

    Node st[4 * N];

    Segment_Tree(){}

    void init(ll i, ll l, ll r, ll *a){
        st[i].lp = 0;
        if(l == r){
            st[i].mn = st[i].mx = st[i].sum = a[l];
            st[i].cnt = 1;
            return;
        }

        ll mid = (l + r) >> 1;
        init(2 * i + 1, l, mid, a);
        init(2 * i + 2, mid + 1, r, a);

        st[i] = merge(st[2 * i + 1], st[2 * i + 2]);
    }

    void push_lazy(ll i, ll l, ll r){
        if(st[i].lp){
            st[i].mx = st[i].mn = st[i].lp;
            st[i].sum = st[i].lp * st[i].cnt;

            if(l != r){
                st[2 * i + 1].lp = st[i].lp;
                st[2 * i + 2].lp = st[i].lp;
            }

            st[i].lp = 0;
        }
    }

    void update(ll i, ll l, ll r, ll sl, ll sr, ll val){
        push_lazy(i, l, r);
        if(sl > r || sr < l) return;
        if(sl <= l && r <= sr){
            st[i].lp = val;
            push_lazy(i, l, r);
            return;
        }

        ll mid = (l + r) >> 1;
        update(2 * i + 1, l, mid, sl, sr, val);
        update(2 * i + 2, mid + 1, r, sl, sr, val);

        st[i] = merge(st[2 * i + 1], st[2 * i + 2]);
    }

    ll find_smaller(ll i, ll l, ll r, ll val){
        push_lazy(i, l, r);
        if(st[i].mn > val) return N + 1;
        if(st[i].mx <= val) return l;

        ll mid = (l + r) >> 1;
        ll lvalue = find_smaller(2 * i + 1, l, mid, val);
        ll rvalue = find_smaller(2 * i + 2, mid + 1, r, val);
        return min(lvalue, rvalue);
    }

    pair<ll, ll> find_big_sum(ll i, ll l, ll r, ll start, ll val){
        //cout << "find_big_sum " << i << " " << l << " " << r << " " << start << " " << val << endl;
        push_lazy(i, l, r);
        if(r < start) return {r, 0};
        if(l >= start){
            if(st[i].sum <= val) return {r, st[i].sum};
            if(st[i].mx > val) return {l - 1, 0};
        }

        ll mid = (l + r) >> 1;
        auto lvalue = find_big_sum(2 * i + 1, l, mid, start, val);
        if(lvalue.first != mid) return lvalue;
        auto rvalue = find_big_sum(2 * i + 2, mid + 1, r, start, val - lvalue.second);
        return {rvalue.first, lvalue.second + rvalue.second};
    }
};

ll n, q;
ll a[N];
Segment_Tree st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];

    st.init(0, 1, n, a);

    for(ll i = 1; i <= q; ++i){
        ll t, x, y;
        cin >> t >> x >> y;

        if(t == 1){
            ll idx = st.find_smaller(0, 1, n, y);
            if(idx <= x)
                st.update(0, 1, n, idx, x, y);
        }
        else{
            ll cnt = 0;
            while(true){
                ll idx = st.find_smaller(0, 1, n, y);
                if(idx > n) break;
                if(idx < x) idx = x;

                auto [idx2, sum] = st.find_big_sum(0, 1, n, idx, y);
                y -= sum;
                cnt += (idx2 - idx + 1);
                if(idx2 == n) break;
            }

            cout << cnt << "\n";
        }
    }
}
/*
10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17
*/