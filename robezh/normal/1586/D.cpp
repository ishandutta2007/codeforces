#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int INF = (int)1e9;
const int N = 105;

int n;

int ask(int pos, int val) {
    cout << "? ";
    rep(i, 1, n + 1) {
        cout << (i == pos ? val : 3 - val) << " ";
    }
    cout << endl;
    fflush(stdout);
    int res;
    cin >> res;
    if(res == 0) res = INF;
    return res;
}

int to[N], in[N];
int res[N];

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    cin >> n;
    fill(to, to + n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int p = ask(i, 1);
        if(p != INF && p != i) to[p] = i, in[i]++;
        p = ask(i, 2);
        if(p != INF && p != i) to[i] = p, in[p]++;
    }
    int rt = -1;
    for (int i = 1; i <= n; i++) {
        if(!in[i]) rt = i;
    }
    for (int i = 1; i <= n; i++) {
        res[rt] = i;
        rt = to[rt];
    }
    cout << "! ";
    rep(i, 1, n + 1) cout << res[i] << " ";
    cout << '\n';
    fflush(stdout);




}