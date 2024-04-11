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
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;
int a[N], b[N];

bool check(int x) {
    int c = 0;
    rep(i, 0, n) {
        if(a[i] + b[i] + 1 < x) continue;
        int l = x - b[i] - 1, r = a[i];
        if(l <= c && c <= r) c++;
    }
    return c >= x;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i] >> b[i];
            swap(a[i], b[i]);
        }
        int l = 0, r = n + 1, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << l << '\n';

    }




}