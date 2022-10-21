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
const int N = (int)1e5 + 50;
const double EPS = 1e-7;

int n, a[N], l;

double getloca(double t) {
    for(int i = 1; i <= n + 1; i++) {
        double delt = (double)(a[i] - a[i - 1]) / i;
        if(t > delt) {
            t -= delt;
        } else {
            return a[i - 1] + t * i;
        }
    }
    return l;
}

double getlocb(double t) {
    for(int i = n; i >= 0; i--) {
        double delt = (double)(a[i + 1] - a[i]) / (n + 1 - i);
        if(t > delt) {
            t -= delt;
        } else {
            return a[i + 1] - t * (n + 1 - i);
        }
    }
    return 0;
}



bool check(double t) {
    return getloca(t) > getlocb(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> l;
        rep(i, 1, n + 1) cin >> a[i];
        a[n + 1] = l;

        double lb = 0, rb = (double)1e9 + 50, mid;
        for(int it = 0; it < 100; it++) {
            mid = (lb + rb) / 2;
            if(check(mid)) rb = mid;
            else lb = mid;
        }
        cout << fixed << setprecision(10) << rb << '\n';
    }



}