#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
        fill(value.begin() + S + leaves.size(), value.end(), zero);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

const int NPRIME = 3;
const int P1 = 1e9+7, P2 = 1e9+9, P3 = 1e9+21;
const int primes[3] = { P1, P2, P3 };

struct mods {
    int vals[NPRIME];

    mods(ll value = 0) {
        for (int i = 0; i < NPRIME; i++) 
            vals[i] = value % primes[i];
    }

    #define combine(h, op) \
        mods res; \
        for (int i = 0; i < NPRIME; i++) \
            res.vals[i] = (vals[i] op h.vals[i]) % primes[i]; \
        return res;

    bool operator==(const mods &h) { return !memcmp(this, &h, sizeof(mods)); }
    mods operator*(const mods &h) { combine(h, * 1ll *); }
    mods operator+(const mods &h) { combine(h, +); }

    mods operator*(ll m) { return (*this) * mods(m); }
    mods operator+(ll a) { return (*this) + mods(a); }
};

const int BASE = 1009;
const int MAXL = 1e5 + 100;
mods powers[MAXL], powsum[MAXL];

void init() {
    powers[0] = mods(1);
    powsum[0] = powers[0];

    for(int i=1; i<MAXL; i++) {
        powers[i] = powers[i-1] * BASE;
        powsum[i] = powsum[i-1] + powers[i];
    }
}

struct node {
    int l;
    mods hash;

    node operator+(const node &o) {
        return { l + o.l, hash * powers[o.l] + o.hash };
    }
};

struct update {
    int v;

    node operator()(node &n) {
        if (v == -1) return n;
        return { n.l, powsum[n.l-1] * v };
    }

    update operator+(const update &o) {
        return o;
    }
};

int N, M, K;
string input;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    init();

    cin >> N >> M >> K;
    cin >> input;

    seg_tree_lazy<node, update> st(N, {0, 0}, {-1});

    vector<node> leaves;
    for (char c : input)
        leaves.push_back({1, mods(c)});
    st.set_leaves(leaves);

    for (int q = 0; q < M + K; q++) {
        int t, l, r, v;
        cin >> t >> l >> r >> v;
        l--, r--;

        if (t == 1) {
            st.upd(l, r, { '0' + v });
        } else {
            if (l > r - v) {
                cout << "YES\n";
                continue;
            }

            mods h1 = st.query(l, r - v).hash;
            mods h2 = st.query(l + v, r).hash;

            if (h1 == h2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}