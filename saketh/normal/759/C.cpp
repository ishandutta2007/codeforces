#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

struct node {
    int eats, gives;
    node(int val = 0) {
        eats = 0;
        gives = 0;

        if (val == 1) gives = 1;
        if (val == -1) eats = 1;
    }
    node operator+(const node &n) const {
        node res;
        res.eats = eats + max(0, n.eats - gives);
        res.gives = max(0, gives - n.eats) + n.gives;
        return res;
    }
};

int find_top(seg_tree<node> &st, vi &vals) {
    int loc = 1;
    if (st.value[loc].gives == 0) return -1;

    TRACE(cout << "Starting search at root: " << st.value[loc].eats << " " << st.value[loc].gives << endl;)
    int eaten = 0;
    while (loc < st.S) {
        node n1 = st.value[2 * loc];
        node n2 = st.value[2 * loc + 1];

        TRACE(cout << "Children look like " << n1.eats << " " << n1.gives << " "
                                      << n2.eats << " " << n2.gives << endl;)

        if (n2.gives > eaten) {
            loc = 2 * loc + 1;
        }
        else {
            eaten -= n2.gives;
            eaten += n2.eats;
            loc = 2 * loc;
        }
    }

    return vals[loc - st.S];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int M;
    cin >> M;

    int ST = M;
    while (__builtin_popcount(ST) != 1) ST++;
    vector<node> leaves(ST);
    
    seg_tree<node> st(ST);
    st.set_leaves(leaves);

    vi val(M);
    for (int i = 0; i < M; i++) {
        int type, index;
        cin >> index >> type;
        index--;

        if (type == 0) {
            // pop
            st.upd(index, node(-1));
        } else {
            // push
            cin >> val[index];
            st.upd(index, node(1));
        }

        cout << find_top(st, val) << "\n";
    }

    return 0;
}