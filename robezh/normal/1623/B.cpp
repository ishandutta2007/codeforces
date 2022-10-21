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
const int N = 1005;

int n;
struct P {
    int l, r, d;
} p[N];
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i].l >> p[i].r;
        }
        sort(p, p + n, [](const P &p1, const P &p2) {
            return p1.r - p1.l < p2.r - p2.l;
        });
        fill(vis + 1, vis + n + 1, false);
        rep(i, 0, n) {
            rep(j, p[i].l, p[i].r + 1) {
                if(!vis[j]) {
                    vis[j] = 1;
                    p[i].d = j;
                    break;
                }
            }
            cout << p[i].l << " " << p[i].r << " " << p[i].d << '\n';
        }
        cout << '\n';
    }

}