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
const int N = (int)2e5 + 50, LOGN = 17;
const int INF = (int)1e9;

int n, k;
int ord[N], in[N], tim = 0;
char las[N];
int lc[N], rc[N];
int res[N];
string str;

void dfs(int v) {
    if(lc[v] != -1) dfs(lc[v]);
    ord[tim] = v;
    in[v] = tim++;
    if(rc[v] != -1) dfs(rc[v]);
}

int solve(int v, int rem) {
    if(v == -1 || rem == 0) return 0;

    int used = 0;
    int lused = solve(lc[v], rem - 1);
    used += lused;
    if(lused || las[v] > str[v]) {
        res[v] = 1;
        used++;
    }
    if(res[v]) {
        used += solve(rc[v], rem - used);
    }
    return used;
}

void print_ans(int v) {
    if(lc[v] != -1) print_ans(lc[v]);
    cout << str[v];
    if(res[v]) cout << str[v];
    if(rc[v] != -1) print_ans(rc[v]);
}

int pos[256];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    cin >> str;
    rep(i, 0, n) {
        cin >> lc[i] >> rc[i];
        lc[i]--, rc[i]--;
    }
    dfs(0);
    fill(pos, pos + 256, INF);
    for (int i = n - 1; i >= 0; i--) {
        pos[str[ord[i]]] = i;
        char f = ' ';
        for (char c = 'a'; c <= 'z'; c++) {
            if(c != str[ord[i]] && pos[f] > pos[c]) f = c;
        }
        las[ord[i]] = f;
    }

    solve(0, k);
    assert(k >= 0);
    print_ans(0);

}