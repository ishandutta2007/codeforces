#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef long double ld;

const int N = (int)2e5 + 50;

int n;

bool same(ll *a, ll *b) {
    for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
    return true;
}

void impossible() {
    cout << "IMPOSSIBLE" << '\n';
    exit(0);
}


ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(same(a, b)) return cout << "SMALL\n0\n\n", 0;
    if(n == 1) impossible();

    vector<pii> res;
    if(n == 2) {
        while(true) {
//            cout << b[0] << " " << b[1] << endl;
            if(b[0] > b[1]) {
                swap(b[0], b[1]);
                res.push_back({0, 0});
            }
            if(b[0] == 0) impossible();
            if(b[0] == a[0] && b[1] >= a[1] && (b[1] - a[1]) % b[0] == 0) {
                res.push_back({1, (b[1] - a[1]) / b[0]});
                break;
            }
            if(b[0] == a[1] && b[1] >= a[0] && (b[1] - a[0]) % b[0] == 0) {
                res.push_back({1, (b[1] - a[0]) / b[0]});
                res.push_back({0, 0});
                break;
            }
            res.push_back({1, b[1] / b[0]});
            b[1] %= b[0];
        }
    } else {
        while(true) {
            if(same(a, b)) {
                break;
            }
            reverse(b, b + n);
            if(same(a, b)) {
                res.push_back({0, 0});
                break;
            }
            reverse(b, b + n);

            for(int i = 0; i < n; i++) if(b[i] <= 0) impossible();
            if(b[0] > b[1]) {
                reverse(b, b + n);
                res.push_back({0, 0});
            }
//            for(int i = 0; i < n; i++) cout << b[i] << " ";
//            cout << endl;
            for(int i = n - 1; i >= 1; i--) {
                b[i] -= b[i - 1];
            }
            res.push_back({1, 1});

        }
    }
    ll tot = 0;
    for(auto p : res) tot += p.second;
//    cout << tot << endl;
    if(tot > (int)2e5) {
        cout << "BIG\n" << tot << "\n" << '\n';
    } else {
        cout << "SMALL\n";
        reverse(all(res));
        string str;
        for(auto p : res) {
            if(p.first) while(p.second--) str.push_back('P');
            else str.push_back('R');
        }
        cout << str.length() << '\n';
        cout << str << "\n";
    }
}