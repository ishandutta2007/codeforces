#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 1e5 + 10;
const int B = 140;

struct Node{
    int next_node;
    int prev_node;
    int jump;
};

int n, q;
Node nodes[N];
bool used[N];

int find_jump(int v) {
    for (int i = 0; i < B; ++i) {
        v = nodes[v].next_node;
    }   
    return v; 
}

void build() {
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int v = i;
        int jump = find_jump(i);
        while (!used[v]) {
            used[v] = true;
            nodes[v].jump = jump;
            v = nodes[v].next_node;
            jump = nodes[jump].next_node;
        }
    }
}

void relax_jumps(int v) {
    int jump = v;
    for (int i = 0; i < B; ++i) {
        v = nodes[v].prev_node;
    }
    for (int i = 0; i <= B; ++i) {
        nodes[v].jump = jump;
        v = nodes[v].next_node;
        jump = nodes[jump].next_node;
    }
}

void upd(int i, int j) {
    int next_i = nodes[i].next_node;
    int next_j = nodes[j].next_node;
    nodes[i].next_node = next_j;
    nodes[j].next_node = next_i;
    nodes[next_i].prev_node = j;
    nodes[next_j].prev_node = i;
    relax_jumps(i);
    relax_jumps(j);
}

int getAns(int v, int k) {
    while (k) {
        if (k >= B) {
            v = nodes[v].jump;
            k -= B;
        } else {
            v = nodes[v].next_node;
            --k;
        }
    }
    return v;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].next_node;
        --nodes[i].next_node;
        nodes[nodes[i].next_node].prev_node = i;
    }
    build();
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            --i;
            --j;
            upd(i, j);
        } else if (t == 2) {
            int v, k;
            cin >> v >> k;
            --v;
            cout << getAns(v, k) + 1 << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}