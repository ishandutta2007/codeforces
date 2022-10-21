#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = 55;

int n;
int num[N];
vector<vi> res;

int getloc(int x) {
    for(int i = 1; i <= n; i++) if(num[i] == x) return i;
    assert(false);
}

vi make(vi vs) {
    vi res;
    for(int x : vs) if(x) res.push_back(x);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> num[i];
    int l = n / 2, r = l + 1;
    vi ts;
    for(int i = 0; i < n; i++) {
        if(r <= n) ts.push_back(r++);
        if(l >= 1) ts.push_back(l--);
    }
//    for(int x : ts) cout << x << " ";
//    cout << endl;

    for(int i = 0; i < n; i++) {
        int tar = getloc(ts[i]);
        vi vs = make({tar - 1, n - i - tar + 1, i});
        reverse(num + 1, num + tar);
        reverse(num + tar, num + n - i + 1);
        reverse(num + n - i + 1, num + n + 1);
        if(i % 2 == 1) reverse(all(vs));
        if(sz(vs) > 1) res.push_back(vs);
//        for(int j = 1; j <= n; j++) cout << num[j] << " ";
//        cout << '\n';
    }
    cout << res.size() << '\n';
    for(auto &vs : res) {
        cout << sz(vs) << " ";
        for(auto &x : vs) cout << x << " ";
        cout << '\n';

    }
}