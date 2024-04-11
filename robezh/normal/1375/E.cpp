#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1005, INF = (int)1e9 + 50;

int n, a[N];
vector<pii> res;
int pos[N];
pii p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i], p[i].first = a[i], p[i].second = i;
    sort(p, p + n);
    rep(i, 0, n) a[p[i].second] = i;
    for(int i = n - 1; i >= 0; i--) {
        rep(j, 0, i + 1) pos[a[j]] = j;
        int s = a[i];
        for(int j = s + 1; j <= i; j++) {
            res.push_back({pos[j], i});
            swap(a[pos[j]], a[i]);
        }
    }
    cout << sz(res) << '\n';
    for(auto p : res) cout << p.first + 1 << " " << p.second + 1 << '\n';
//    rep(i, 0, n) cout << a[i] << " ";
//    cout << endl;



}