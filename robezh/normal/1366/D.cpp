#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e7 + 50;

int n;
int p[N];
int res[(int)5e5 + 50][2];
int xs[N], sz;
int ans[N][2];

pii solve(int i) {
    int x = i, y = i;
    vi vs;
    while(y > 1) {
        vs.push_back(p[y]);
        y /= p[y];
    }
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());
    for(int u = 0; u < sz(vs); u++) {
        for(int v = u + 1; v < sz(vs); v++) {
            if(__gcd(vs[u] + vs[v], i) == 1) {
                return {vs[u], vs[v]};
            }
        }
    }
    if(sz(vs) > 1) {
        sz = 0;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                for(int k = 0; k < sz; k++) {
                    if(__gcd(j + xs[k], i) == 1)
                        return {j, xs[k]};
                }
                xs[sz++] = j;
                for(int k = 0; k < sz; k++) {
                    if(__gcd(x / j + xs[k], i) == 1)
                        return {x / j, xs[k]};
                }
            }
        }
    }
    return {-1, -1};
}

pii brute(int x) {
    for(int i = 2; i <= x; i++) {
        for(int j = 2; j <= x; j++) {
            if(x % i == 0 && x % j == 0 && __gcd(i + j, x) == 1) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 0, N) p[i] = i;
    for(int i = 2; i < N; i++) {
        if(p[i] == i) {
            for(int j = i; j < N; j += i) p[j] = i;
        }
//        for(int j = i; j < N; j += i) dvs[j]++;
    }
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int x; cin >> x;
        if(!ans[x][0]) {
            tie(ans[x][0], ans[x][1]) = solve(x);
        }
        res[t][0] = ans[x][0], res[t][1] = ans[x][1];
//        cout << ans[x][0] << " " << ans[x][1] << " ";
//        auto p = brute(x);
//        cout << p.first << " " << p.second << endl;
    }
    for(int t = 0; t < T; t++) cout << res[t][0] << " ";
    cout << '\n';
    for(int t = 0; t < T; t++) cout << res[t][1] << " ";
    cout << '\n';
}