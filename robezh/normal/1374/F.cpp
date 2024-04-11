#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
const int N = 505;

int n;
int a[N], c[N];
pii p[N];
vi res;

void rotate(int i) {
    int tmp = c[i + 2];
    c[i + 2] = c[i + 1];
    c[i + 1] = c[i];
    c[i] = tmp;
    res.push_back(i);
}

void solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i], p[i] = {a[i], i};
    sort(p, p + n);
    for(int i = 0; i < n; i++) c[p[i].second] = i;
    int cntinv = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) cntinv += (c[i] > c[j]);
    }
    if(cntinv % 2 != 0) {
        int found = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j]) {
                    swap(c[i], c[j]);
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        if(!found) {
            cout << -1 << '\n';
            return ;
        }
    }
//    for(int i = 0; i < n; i++) cout << c[i] << " ";
//    cout << endl;
    res.clear();
    for(int i = 0; i < n - 3; i++) {
        int cur;
        for(cur = 0; cur < n; cur++) if(c[cur] == i) break;
        while(cur >= i + 2) {
            rotate(cur - 2);
            cur -= 2;
//                for(int i = 0; i < n; i++) cout << c[i] << " ";
//    cout << endl;
        }
        if(cur == i + 1) {
            rotate(cur);
            rotate(i);
//            for(int i = 0; i < n; i++) cout << c[i] << " ";
//            cout << endl;
        }
    }
    while(!(c[n - 3] == n - 3 && c[n - 2] == n - 2 && c[n - 1] == n - 1)) rotate(n - 3);
//    for(int i = 0; i < n; i++) cout << c[i] << " ";
//    cout << endl;
    cout << sz(res) << '\n';
    for(int x : res) cout << x + 1 << " ";
    cout << '\n';
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();

    }

}