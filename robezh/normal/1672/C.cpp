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

const int N = (int)2e5 + 50;

int n;
int a[N];
vi x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        x.clear();
        rep(i, 0, n) {
            cin >> a[i];
            if(i && a[i - 1] == a[i]) {
                x.push_back(i);
            }
        }
        if(sz(x) <= 1) cout << 0 << '\n';
        else {
            cout << max(1, x.back() - x[0] - 1) << '\n';
        }
    }




}