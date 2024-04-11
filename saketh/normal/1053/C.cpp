#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int MOD = 1e9 + 7;
int norm(int arg) {
    int res = arg % MOD;
    if (res < 0) res += MOD;
    return res;
}
int sum(int a, int b) { return (a + b) % MOD; }
int diff(int a, int b) { return (a + MOD - b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct range {
    int pos;
    int elt;
    int tot;
    int ans;

    range() { elt = 0; }
    range(int _pos, int _val) {
        pos = norm(_pos);
        elt = 1;
        tot = norm(_val);
        ans = 0;
    }
    range operator+(const range &o) const {
        if (elt == 0) return o;
        if (o.elt == 0) return *this;

        range res;
        int move = diff(o.pos, sum(pos, elt));
        res.ans = sum(sum(ans, o.ans), prod(move, o.tot));
        res.tot = sum(tot, o.tot);
        res.elt = sum(elt, o.elt);
        res.pos = pos;
        return res;
    }
};

struct range_back {
    int pos;
    int elt;
    int tot;
    int ans;

    range_back() { elt = 0; }
    range_back(int _pos, int _val) {
        pos = norm(_pos);
        elt = 1;
        tot = norm(_val);
        ans = 0;
    }
    range_back operator+(const range_back &o) const {
        if (elt == 0) return o;
        if (o.elt == 0) return *this;
        if (pos > o.pos) return o + *this;

        range_back res;
        int move = diff(diff(o.pos, o.elt), pos);
        res.ans = sum(sum(ans, o.ans), prod(move, tot));
        res.tot = sum(tot, o.tot);
        res.elt = sum(elt, o.elt);
        res.pos = o.pos;
        return res;
    }
};

template<typename T> struct BIT {
    int S;
    vector<T> v;

    BIT<T>(int _S) {
        S = _S;
        v.resize(S+1);
    }

    void update(int i, T k) {
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i) {
        T res = 0;
        for(i++; i; i-=i&-i)
            res = res + v[i];
        return res;
    }

    T read(int l, int r) {
        return read(r) - read(l-1);
    }

    // returns first index i such that read(i) >= v, if it exists
    // returns N otherwise
    int lower_bound(T val) {
        T cur = 0;
        int pos = 0;
        for (int i = 20; i >= 0; i--) {
            int nxt = pos + (1 << i);
            if (nxt < S && cur + v[nxt] < val) {
                cur += v[nxt];
                pos = nxt;
            }
		}
        /*TRACE(
                if (pos) assert(read(pos - 1) < val);
                if (pos != S-1) assert(read(pos) >= val);
        )*/
        return pos;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    vi pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    vi wt(N);
    BIT<ll> wt_sum(N);
    for (int i = 0; i < N; i++) {
        cin >> wt[i];
        wt_sum.update(i, wt[i]);
    }

    vector<range> leaves(N);
    for (int i = 0; i < N; i++)
        leaves[i] = range(pos[i], wt[i]);
    seg_tree<range> st_forw(N);
    st_forw.set_leaves(leaves);

    vector<range_back> leaves_back(N);
    for (int i = 0; i < N; i++)
        leaves_back[i] = range_back(pos[i], wt[i]);
    seg_tree<range_back> st_back(N);
    reverse(all(leaves_back));
    st_back.set_leaves(leaves_back);

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            // update
            x = -x - 1;
            wt_sum.update(x, y - wt[x]);
            wt[x] = y;
            st_forw.upd(x, range(pos[x], y));
            st_back.upd(N - 1 - x, range_back(pos[x], y));
        } else {
            // read
            x--, y--;
            ll pref = wt_sum.read(x - 1);
            ll tot_w = wt_sum.read(x, y);
            int meet = wt_sum.lower_bound(pref + (tot_w+1)/2);
            int right = st_forw.query(meet, y).ans;
            int left = st_back.query((N-1) - meet, (N - 1) - x).ans;
            cout << sum(right, left) << "\n";
        }
    }

    return 0;
}