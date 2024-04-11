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

const int INF = 1e9;
constexpr int dig[5] = { 2, 0, 1, 7, -1 };

struct node {
    array<array<int, 5>, 5> cost;

    void init() { 
        for (auto &a : cost)
            fill(all(a), INF);
        for (int i = 0; i < 5; i++)
            cost[i][i] = 0;
    }
    node() { init(); }
    node(int val) {
        init();

        for (int i = 0; i < 5; i++) {
            if (val == dig[i]) {
                cost[i][i] = 1;
                cost[i][i+1] = 0;
            }
        }

        if (val == 6) {
            cost[3][3]++;
            cost[4][4]++;
        }
    }

    node operator+(const node &app) const {
        node res;
        for (int i = 0; i < 5; i++) res.cost[i][i] = INF;
        for (int i = 0; i < 5; i++)
            for (int j = i; j < 5; j++)
                for (int k = j; k < 5; k++)
                    res.cost[i][k] = min(res.cost[i][k], cost[i][j] + app.cost[j][k]);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    string str;
    cin >> N >> Q >> str;

    vector<node> leaves(str.size());
    for (int i = 0; i < N; i++)
        leaves[i] = node(str[i] - '0');

    seg_tree<node> st(N);
    st.set_leaves(leaves);

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;

        int ans = st.query(l - 1, r - 1).cost[0][4];
        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}