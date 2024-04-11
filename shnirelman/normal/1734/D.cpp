#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;

vector<pli> get(vector<int> a) {
    li cur = 0;
    li mn = 0;
    vector<pli> res;
    for(int i = 0; i < a.size(); i++) {
        cur += a[i];
        mn = min(mn, cur);

        if(cur > 0 || i + 1 == a.size()) {
            res.emplace_back(-mn, cur);
            cur = 0;
            mn = 0;
        }
    }

    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    k--;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(k == 0 || k == n - 1) {
        cout << "YES\n";
        return;
    }

    vector<int> b, c;
    for(int i = k - 1; i >= 0; i--)
        b.push_back(a[i]);
    for(int i = k + 1; i < n; i++)
        c.push_back(a[i]);

//    cout << "b ";
//    for(auto x : b)
//        cout << x << ' ';
//    cout << endl;
//    cout << "c ";
//    for(auto x : c)
//        cout << x << ' ';
//    cout << endl;

    vector<pair<li, li>> b1 = get(b), c1 = get(c);

//    cout << "b1 " << endl;
//    for(auto x : b1)
//        cout << x.f << ' ' << x.s << "   ||  ";
//    cout << endl;
//    cout << "c1 " << endl;
//    for(auto x : c1)
//        cout << x.f << ' ' << x.s << "   ||  ";
//    cout << endl;

    li cur = a[k];
    int x = 0, y = 0;
    while(x < b1.size() && y < c1.size()) {
//        cout << x << ' ' << y << ' ' << cur << endl;
        if(cur >= b1[x].f) {
            cur += b1[x].s;
            x++;
        } else if(cur >= c1[y].f) {
            cur += c1[y].s;
            y++;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}