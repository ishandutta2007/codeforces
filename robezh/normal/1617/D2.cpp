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

int get(int a, int b, int c) {
    cout << "? " << a + 1 << " " << b + 1 << " " << c + 1 << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

const int N = (int)1e4 + 50;
int n;
int gd[N];
int res[N];
int g0 = -1, g1 = -1;
int z0, z1;

void solve(int i) {
    if(gd[i]) {
        int x = get(i * 3, i * 3 + 1, z0);
        int y = get(i * 3, i * 3 + 2, z0);
        res[i * 3] = res[i * 3 + 1] = res[i * 3 + 2] = 1;
        if(!x && y) res[i * 3 + 1] = 0;
        else if(x && !y) res[i * 3 + 2] = 0;
        else if(!x && !y) res[i * 3] = 0;
    } else {
        int x = get(i * 3, i * 3 + 1, z1);
        int y = get(i * 3, i * 3 + 2, z1);
        res[i * 3] = res[i * 3 + 1] = res[i * 3 + 2] = 0;
        if(!x && y) res[i * 3 + 2] = 1;
        else if(x && !y) res[i * 3 + 1] = 1;
        else if(x && y) res[i * 3] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        g0 = g1 = -1;
        cin >> n;
        rep(i, 0, n / 3) {
            gd[i] = get(i * 3, i * 3 + 1, i * 3 + 2);
            if(gd[i]) g1 = i;
            else g0 = i;
        }
        int d1 = get(g0 * 3 + 1, g0 * 3 + 2, g1 * 3);
        int d2 = get(g0 * 3 + 2, g1 * 3, g1 * 3 + 1);
        if(d1) {
            z0 = g0 * 3;
            z1 = g1 * 3;
        } else if(d2) {
            z0 = g0 * 3 + 1;
            z1 = g1 * 3 + 1;
        } else {
            z0 = g0 * 3 + 2;
            z1 = g1 * 3 + 2;
        }
        res[z0] = 0;
        res[z1] = 1;
        for (int x : {g0 * 3, g0 * 3 + 1, g0 * 3 + 2, g1 * 3, g1 * 3 + 1, g1 * 3 + 2}) {
            if(x != z0 && x != z1) res[x] = get(z0, z1, x);
        }
        rep(i, 0, n / 3) {
            if(i != g0 && i != g1) solve(i);
        }
        vi rs;
        rep(i, 0, n) if(!res[i]) rs.push_back(i);
        cout << "! " << sz(rs) << " ";
        for (int x : rs) cout << x + 1 << " ";
        cout << endl;
        fflush(stdout);
    }

}