#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

struct knight {
    ll begin, end, empty;
    knight(int t = 0, int d = 0) {
        begin = t;
        end = begin + d;
        empty = 0;
    }
    knight operator+(const knight& o) const {
        knight res;
        if (end >= o.begin) {
            ll compr = min(o.empty, end - o.begin);
            res.begin = begin;
            res.end = o.end + (end - o.begin) - compr;
            res.empty = empty + o.empty - compr;
        } else {
            res.begin = begin;
            res.end = o.end;
            res.empty = empty + o.begin - end + o.empty;
        }
        return res;
    }
};

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXT = 1e6 + 1;
    seg_tree<knight> st(MAXT);

    int Q;
    cin >> Q;
    vi t(Q);
    for (int q = 0; q < Q; q++) {
        char op;
        cin >> op;
        if (op == '+') {
            cin >> t[q];
            int d;
            cin >> d;
            st.upd(t[q], knight(t[q], d));
        } else if (op == '-') {
            int i;
            cin >> i;
            st.upd(t[i-1], knight());
        } else {
            int t;
            cin >> t;
            cout << max(0ll, st.query(0, t).end - t) << "\n";
        }
    }

    return 0;
}