#include<bits/stdc++.h>
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

using namespace std;

typedef long long ll;
typedef pair<int, ll> Pi;
const int N = 100500;
const ll INF = (ll)1e18 + 50;

int n,q;
int num[N], dif[N];
ll psum[N];

struct Tree {
    ll add[4*N], sum[4*N];

    void push_down(int x, int l, int r) {
        if(add[x] != 0) {
            if(l < r) {
                int mid = (l + r) / 2;
                sum[ls(x)] += add[x] * (mid - l + 1);
                add[ls(x)] += add[x];
                sum[rs(x)] += add[x] * (r - mid);
                add[rs(x)] += add[x];
            }
            add[x] = 0;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        if(l == r) {sum[x] = num[l]; add[x] = 0; return ;}
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        add[x] = 0; sum[x] = sum[ls(x)] + sum[rs(x)];
    }

    ll query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;

        push_down(x, l, r);

        if(l >= a && r <= b) return sum[x];

        ll LHS = query(a, b, ls(x), l, mid);
        ll RHS = query(a, b, rs(x), mid+1, r);
        return LHS + RHS;
    }

    void update(int a, int b, int x, int l, int r, ll delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        if(l < r) push_down(x, l, r);

        if(l >= a && r <= b) {
            sum[x] += delta * (r - l + 1);
            add[x] += delta;
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        sum[x] = sum[ls(x)] + sum[rs(x)];
    }

    void update(int a, int b, ll delta) {
//        cout << "updating " << a << ", " << b << " with " << delta << endl;
        update(a, b, 0, 0, n-1, delta);
    }

} tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    tree.init();
    for(int i = 1; i < n; i++) cin >> dif[i], psum[i] = psum[i-1] + dif[i];

    map<int, ll> mp;
    for(int i = 0; i < n; i++) mp[i] = num[i];
    cin >> q;
    while(q--) {
        char c;
        cin >> c;
        if(c == 's') {
            int l, r; cin >> l >> r; l--, r--;
            cout << tree.query(l, r) << "\n";
        }
        else {
            int i, x; cin >> i >> x; i--;
            auto it = mp.upper_bound(i);
            it--;
            if(it->first != i) {
                mp[i] = it->second + psum[i] - psum[it->first];
            }
            mp[i] += x;
            int la_i = i;
            ll la_val = mp[i];
            it = mp.upper_bound(i);
            tree.update(la_i, (it == mp.end() ? n - 1 : it->first - 1), x);
            while(it != mp.end()) {
                if(it->second > la_val + psum[it->first] - psum[la_i]) break;
                ll delta = la_val + psum[it->first] - psum[la_i] - it->second;
                la_val += psum[it->first] - psum[la_i], la_i = it->first;
                it = mp.erase(it);
                tree.update(la_i, (it == mp.end() ? n - 1 : it->first - 1), delta);
            }
        }
    }
}