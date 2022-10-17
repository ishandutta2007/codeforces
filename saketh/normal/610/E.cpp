#include <bits/stdc++.h>
using namespace std;

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

const int SIGMA = 10;

bool ok(char c) {
    if (c < 'a') return false;
    return c - 'a' < SIGMA;
}

struct node {
    int len;
    char left, right;
    int trans[100];

    node(char c = 0, int _len = 0) {
        len = _len;
        left = c, right = c;
        memset(trans, 0, sizeof(trans));
    }

    int &operator()(int i, int j) {
        return trans[10 * i + j];
    }

    node operator+(const node &n) const {
        node res(0, 0);

        res.len = len + n.len;
        res.left = left;
        res.right = n.right;

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                res(i, j) = trans[10 * i + j] + n.trans[10 * i + j];
            }
        }

        if (ok(right) && ok(n.left)) {
            res(right - 'a', n.left - 'a')++;
        }

        return res;
    }
};

struct update {
    char rep;

    update(char _rep = 0) {
        rep = _rep;
    }

    update operator+(const update &u) const {
        if (u.rep == 0) return *this;
        return u;
    }

    node operator()(const node &n) {
        if (rep == 0) return n;

        node res(rep, n.len);
        res(rep-'a', rep-'a') = n.len - 1;
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, M, K;
    string str;

    cin >> N >> M >> K >> str;

    seg_tree_lazy<node, update> st(N);

    for (int i = 0; i < N; i++) {
        st.value[st.S + i] = node(str[i], 1);
    }

    for (int i = st.S - 1; i > 0; i--)
        st.value[i] = st.value[2 * i] + st.value[2 * i + 1];

    int type, i, j;
    string query;
    char let;

    for (int q = 0; q < M; q++) {
        cin >> type;

        if (type == 1) {
            cin >> i >> j >> let;
            i--, j--;

            st.upd(i, j, update(let));
        } else {
            cin >> query;

            node root = st.query(0, N - 1);

            int ans = 1;
            for (int a = 0; a < K; a++) {
                for (int b = 0; b <= a; b++) {
                    ans += root(query[a]-'a', query[b]-'a');
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}