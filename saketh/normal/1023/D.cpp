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

struct node {
    int v;
    node(int _v = 0) { v = _v; }
    node operator+(const node &o) {
        return node(max(v, o.v));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, Q;
    cin >> N >> Q;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    // find the first and last occurence of everything
    vi first(Q + 1, -1), last(Q + 1, -1);
    for (int i = 0; i < N; i++) {
        if (first[vals[i]] == -1) {
            first[vals[i]] = i;
        }
        last[vals[i]] = i;
    }

    // always assume the first query hits everything
    first[1] = 0;
    last[1] = N - 1;

    // if we don't see the last query, we need to put it on a zero
    if (first[Q] == -1) {
        if (first[0] == -1) {
            cout << "NO\n";
            return 0;
        }
        first[Q] = first[0];
        last[Q] = first[0];
    }

    // anything else that doesn't appear, hide it behind the last query
    for (int q = Q - 1; q >= 1; q--) {
        if (first[q] == -1) {
            first[q] = first[Q];
            last[q] = last[Q];
        }
    }

    // put together all the events
    vvi get(N), lose(N);
    for (int q = 1; q <= Q; q++) {
        get[first[q]].push_back(q);
        lose[last[q]].push_back(q);
    }

    // now just reconstruct
    vi res(N);
    seg_tree<node> avail(Q + 1);
    for (int i = 0; i < N; i++) {
        for (int v : get[i]) {
            avail.upd(v, node(v));
        }
        res[i] = avail.query(0, Q).v;
        for (int v : lose[i]) {
            avail.upd(v, node(0));
        }
    }

    for (int i = 0; i < N; i++) {
        if (vals[i] != 0 && res[i] != vals[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int v : res)
        cout << v << " ";
    cout << endl;

    return 0;
}