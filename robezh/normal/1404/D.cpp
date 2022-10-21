#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e6 + 50;

int n;
vi G[N];
int at[N];
int col[N];
ll sum = 0;

void dfs(int v, int c) {
    col[v] = c;
    sum += v * c;
    for (int nxt : G[v]) {
        if(col[nxt] == -1) dfs(nxt, !c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    if(n % 2 == 0) {
        cout << "First" << endl;
        rep(i, 0, n) cout << i + 1 << " ";
        rep(i, 0, n) cout << i + 1 << " ";
        cout << endl;
        fflush(stdout);
    } else {
        cout << "Second" << endl;
        rep(i, 1, 2 * n + 1) {
            int x; cin >> x;
            if(at[x]) {
                G[at[x]].push_back(i);
                G[i].push_back(at[x]);
            }
            else at[x] = i;
        }
        rep(i, 1, n + 1) {
            G[i].push_back(i + n);
            G[i + n].push_back(i);
        }
        memset(col, -1, sizeof(col));
        rep(i, 1, 2 * n + 1) {
            if(col[i] == -1) dfs(i, 0);
        }
        int f = sum % (2 * n) == n;

        rep(i, 1, 2 * n + 1) {
            if (col[i] ^ f) cout << i << " ";
        }
        cout << endl;
        fflush(stdout);
    }
}