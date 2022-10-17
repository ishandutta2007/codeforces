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
    int ans, width;
    int lDec, lInc;
    int rInc, rDec;
    bool wDec, wInc;

    void print() const {
        TRACE(
        cout << "ans=" << ans << " width=" << width
            << " lDec=" << lDec << " lInc=" << lInc
            << " rInc=" << rInc << " rDec=" << rDec
            << " wDec=" << wDec << " wInc=" << wInc;
        cout << endl;
        );
    }

    node() {
        width = 0;
    }

    node(ll val) {
        ans = 1;
        width = 1;
        wDec = false, wInc = false;
        if (val == 0) {
            ans = lDec = lInc = rInc = rDec = 0;
        } else if (val < 0) {
            lDec = 1; lInc = 0;
            rInc = 0; rDec = 1;
            wDec = true;
        } else {
            lDec = 0, lInc = 1;
            rInc = 1, rDec = 0;
            wInc = true;
        }
    }

    node operator+(const node &n) const {
        if (n.width == 0) return *this;
        if (width == 0) return n;

        node sum;
        sum.width = width + n.width;
        sum.wDec = wDec & n.wDec;
        sum.wInc = wInc & n.wInc;

        sum.ans = max(ans, n.ans);
        sum.ans = max(sum.ans, rInc + max(n.lInc, n.lDec));
        sum.ans = max(sum.ans, rDec + n.lDec);

        sum.lDec = lDec, sum.lInc = lInc;
        if (wDec) sum.lDec += n.lDec;
        if (wInc) sum.lInc += max(n.lDec, n.lInc);
        else if (lInc == width) sum.lInc += n.lDec;

        sum.rDec = n.rDec, sum.rInc = n.rInc;
        if (n.wInc) sum.rInc += rInc;
        if (n.wDec) sum.rDec += max(rDec, rInc);
        else if (n.rDec == n.width) sum.rDec += rInc;

        TRACE(
        cout << "Added "; print();
        cout << "To "; n.print();
        cout << "Producing "; sum.print();
        );

        return sum;
    }
};

int sanit(ll arg) {
    if (!arg) return 0;
    return (arg > 0) ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi init(N);
    for (int i = 0; i < N; i++)
        cin >> init[i];

    vll diff(N);
    for (int i = 0; i < N - 1; i++) {
        diff[i] = init[i+1] - init[i];
    }

    vector<node> leaves(N);
    for (int i = 0; i < N; i++) {
        leaves[i] = node(sanit(diff[i]));
    }

    int SN = 1;
    while (SN < N)
        SN <<= 1;
    seg_tree<node> st(SN);

    st.set_leaves(leaves);

    int M;
    cin >> M;

    for (int m = 0; m < M; m++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;

        if (l > 0) {
            diff[l-1] += d;
            st.upd(l-1, node(sanit(diff[l-1])));
        }

        if (r < N - 1) {
            diff[r] -= d;
            st.upd(r, node(sanit(diff[r])));
        }

        cout << st.query(0, N-1).ans + 1 << "\n";
    }

    return 0;
}