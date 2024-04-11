#include <bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;


struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;


int n, m, k;
vector<int> G[N];
int deg[N], in[N], inque[N];
hash_map<int, int> mp[N];
int cli[N], csz = 0;

bool check() {
    for(int i = 0; i < csz; i++) {
        for(int j = i + 1; j < csz; j++) {
            int x = cli[i], y = cli[j];
            if(x > y) swap(x, y);
            if(!mp[x][y]) return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m >> k;
    rep(i, 0, n) {
        mp[i].clear();
        G[i].clear();
    }
    fill(deg, deg + n, 0);
    rep(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        if(a > b) swap(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
        mp[a][b] = 1;
        deg[a]++;
        deg[b]++;
    }
    fill(in, in + n, 1);
    fill(inque, inque + n, 0);
    queue<int> que;
    rep(i, 0, n) {
        if(deg[i] < k) {
            que.push(i);
            inque[i] = 1;
        }
    }
    while(!que.empty()) {
        int i = que.front(); que.pop();
//        cout << i << " " << deg[i] << endl;
        if(deg[i] == k - 1) {
            csz = 0;
            for(int nxt : G[i]) if(in[nxt]) cli[csz++] = nxt;
            assert(csz == k - 1);

            if(check()) {
                cout << 2 << '\n';
                rep(j, 0, csz) cout << cli[j] + 1 << " ";
                cout << i + 1;
                cout << '\n';
                return ;
            }

        }
        in[i] = 0;
        for(int nxt : G[i]) {
            if(in[nxt]) {
                deg[nxt]--;
                if(deg[nxt] < k && !inque[nxt]) {
                    que.push(nxt);
                    inque[nxt] = 1;
                }
            }
        }
    }
    vi res;
    rep(i, 0, n) if(in[i]) res.push_back(i);
    if(res.empty()) cout << -1 << '\n';
    else {
        cout << 1 << " " << sz(res) << '\n';
        for(int x : res) cout << x + 1 << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}