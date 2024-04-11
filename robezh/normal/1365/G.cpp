#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1005, Q = 13;

ll b1[N], b2[N];

ll ask(vi v) {
//    ll res = 0;
//    for(int x : v) res |= b1[x];
//    return res;

    if(v.empty()) return 0;
    cout << "? " << sz(v) << " ";
    for(int x : v) cout << x + 1 << " ";
    cout << '\n';
    fflush(stdout);
    ll res;
    cin >> res;
    return res;
}


int n;
ll vals[Q], res[N];
int masks[N];
vi qs[Q];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
    cin >> n;

//    for(int i = 0; i < n; i++) {
//        b1[i] = rng() % 1000000000;
//        for(int j = 0; j < n; j++) {
//            if(i != j) b2[j] |= b1[i];
//        }
//    }

    int cur = 0;
    for(int i = 0; i < (1 << Q); i++) {
        if(__builtin_popcount(i) != Q / 2) continue;
        masks[cur] = i;
        for(int b = 0; b < Q; b++) {
            if(i >> b & 1) qs[b].push_back(cur);
        }
        cur++;
        if(cur == n) break;
    }
    for(int i = 0; i < Q; i++) vals[i] = ask(qs[i]);

    for(int i = 0; i < n; i++) {
        for(int b = 0; b < Q; b++) {
            if(!(masks[i] >> b & 1)) res[i] |= vals[b];
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << '\n';
    fflush(stdout);

//    cout << "! ";
//    for(int i = 0; i < n; i++) cout << b2[i] << " ";
//    cout << '\n';

}