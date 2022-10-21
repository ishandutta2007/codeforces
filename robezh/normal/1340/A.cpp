#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define what_is(x) cerr << #x << " is " << x << endl;

const int N = (int)1e5 + 50;

int n, p[N];
int f[N], s[N];
multiset<int> S;
int in[N];

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void add(int x, int d) {
    if(f[n-1] != -1 && find(x) == find(n - 1)) return ;
    if(d == 1) S.insert(s[find(x)]);
    else S.erase(S.find(s[find(x)]));
}
void unite(int x, int y) {
    x = find(x), y = find(y);
    add(x, -1);
    add(y, -1);
    s[y] += s[x];
    f[x] = y;
    add(y, 1);
}

void solve() {
    S.clear();
    cin >> n;
    for(int i = 0; i < n; i++) {
        f[i] = -1;
        s[i] = 1;
        int x; cin >> x; x--;
        p[x] = i;
     }
    for(int i = 0; i < n; i++) {
        int x = p[i];
        int mx = S.empty() ? 0 : *(--S.end());
        int p = (x == 0 || f[x - 1] == -1) ? 0 : s[find(x - 1)];
//        cout << i << ": " << mx << " " << p << endl;
        if(p != mx) {
            cout << "No" << endl;
            return ;
        }
        f[x] = x;
        add(x, 1);
        if(x >= 1 && f[x - 1] >= 0) unite(x, x - 1);
        if(x + 1 < n && f[x + 1] >= 0) unite(x, x + 1);
    }
    cout << "Yes" << endl;
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