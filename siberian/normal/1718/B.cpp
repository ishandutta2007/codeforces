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

#define int ll

struct Block{
    int len;
    int id;
    Block() = default;
    Block(int len_, int id_) : len(len_), id(id_) {}
    bool operator<(const Block& other) const {
        return len < other.len;
    }
};

const int N = 60;
int fib[N];

void build() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i < N; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

bool check(vector<Block> blocks) {
    sort(all(blocks));
    if (blocks[0].len != 0) {
        return false;
    }
    if (blocks.size() > 1 && blocks[1].len != 0) {
        return false;
    }
    for (int i = 2; i < (int)blocks.size(); ++i) {
        if (blocks[i].len != i) {
            return false;
        }
    }
    for (int i = 1; i < (int)blocks.size(); ++i) {
        if (blocks[i].id == blocks[i - 1].id) {
            return false;
        }
        if (i == 1) {
            ++i;
        }
    }
    return true;
}

vector<Block> get(int x, int id) {
    vector<Block> blocks;
    for (int i = N - 1; i >= 0 && x > 0; --i) {
        if (i == 1) {
            --i;
        }
        while (fib[i] <= x) {
            x -= fib[i];
            blocks.push_back(Block(i, id));
        }
    }
    return blocks;
}

vector<Block> split(Block block) {
    if (block.len % 2 == 0) {
        return {block};
    }
    vector<Block> ans;
    for (int i = block.len - 1; i >= 0; i -= 2) {
        ans.push_back({i, block.id});
    }
    return ans;
}

void solve() {
    int k;
    vector<Block> blocks;
    cin >> k;
    vector<int> a(k);
    vin(a);
    for (int i = 0; i < k; ++i) {
        auto has = get(a[i], i);
        for (auto block : has){
            blocks.push_back(block);
        }
    }
    if (blocks.size() > N) {
        cout << "NO\n";
        return;
    }
    if (check(blocks)) {
        cout << "YES\n";
        return;
    }
    for (int id1 = 0; id1 < (int)blocks.size(); ++id1) {
        auto has = split(blocks[id1]);
        vector<Block> candidate = has;
        for (int i = 0; i < (int)blocks.size(); ++i) {
            if (i == id1) {
                continue;
            }
            candidate.push_back(blocks[i]);
        }
        if (check(candidate)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}