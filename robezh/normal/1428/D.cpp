#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)1e5 + 50;

int n;
int a[N];

int ct = 0;
int cor[N];
vector<pii> res;

int gnxt(vi &v) {
    int res = v.back();
    v.pop_back();
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    vi lone, ltwo;
    for(int i = n; i >= 1; i--) {
        if(a[i] == 1) {
            cor[i] = ++ct;
            res.push_back({i, cor[i]});
            lone.push_back(i);
        } else if(a[i] == 2) {
            if(lone.empty()) {
                cout << "-1" << endl;
                return 0;
            } else {
                int nxt = gnxt(lone);
                res.push_back({i, cor[nxt]});
                ltwo.push_back(i);
            }
        } else if(a[i] == 3){
            if(ltwo.empty() && lone.empty()) {
                cout << "-1" << endl;
                return 0;
            } else {
                int nxt = !ltwo.empty() ? gnxt(ltwo) : gnxt(lone);
                cor[i] = ++ct;
                res.push_back({i, cor[i]});
                res.push_back({nxt, cor[i]});
                ltwo.push_back(i);
            }
        }
    }
    if(ct > n) {
        cout << "-1" << endl;
        return 0;
    }
    cout << sz(res) << '\n';
    for(pii p : res) cout << n + 1 - p.second << " " << p.first<< '\n';

}