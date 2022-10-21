#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;


int n, q;
string str;
int psum[N];
vector<pii> qrs[N];
map<int, int> las;
vi res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        cin >> n >> q;
        cin >> str;
        str = " " + str;
        las.clear();
        rep(i, 0, n + 1) qrs[i].clear();
        rep(i, 1, n + 1) {
            if((str[i] == '-') ^ (i % 2 == 0)) psum[i] = 1;
            else psum[i] = -1;
            psum[i] += psum[i - 1];
        }
        rep(i, 0, q) {
            int l, r; cin >> l >> r;
            qrs[r].push_back({l, i});
//            int d = abs(psum[r] - psum[l - 1]);
//
//            if(d % 2 == 1) cout << 1 << "\n";
//            else if(d == 0) cout << 0 << '\n';
//            else cout << 2 << '\n';
        }
        for(int r = 1; r <= n; r++) {
            las[psum[r - 1]] = r;
            for(auto p : qrs[r]) {
                int l = p.first;
                int d = abs(psum[r] - psum[l - 1]);
                int s = psum[r] - psum[l - 1];

                if(d == 0) continue;
                if(d % 2 == 1) {
                    if(s > 0) {
                        res[p.second].push_back(las[psum[r] - (d / 2 + 1)]);
                    } else {
                        res[p.second].push_back(las[psum[r] + (d / 2 + 1)]);
                    }
                } else if(d > 0) {
                    d = abs(psum[r] - psum[l]);
                    s = psum[r] - psum[l];
                    if(s > 0) {
                        res[p.second].push_back(las[psum[r] - (d / 2 + 1)]);
                    } else {
                        res[p.second].push_back(las[psum[r] + (d / 2 + 1)]);
                    }
                    res[p.second].push_back(l);
                }
            }
        }
        rep(i, 0, q) {
            cout << sz(res[i]) << '\n';
            for (int x : res[i]) cout << x << " ";
            cout << '\n';
            res[i].clear();
        }
    }




}