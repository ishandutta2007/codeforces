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

const int N = (int)1e5 + 50;

int n, k;
int a[N];

bool nei() {
    rep(i, 0, n - 1) if(a[i] + 1 == a[i + 1]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        sort(a, a + n);
        int cnt0 = 0, cnt1 = 0;
        rep(i, 0, n) {
            cnt0 += a[i] == 0;
            cnt1 += a[i] == 1;
        }
        if(cnt0 == 0 && cnt1 == 0) cout << "YES\n";
        else if(cnt0 && cnt1) {
            cout << "NO\n";
        } else if(cnt0) {
            cout << "YES\n";
        } else {
            cout << (nei() ? "YES" : "NO") << '\n';
        }
    }

}