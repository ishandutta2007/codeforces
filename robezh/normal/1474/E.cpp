#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef array<int, 2> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int p[N];
void take(int i) {
    cout << p[i] + 1 << " " << i + 1 << "\n";
    p[i] = p[p[i]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n; cin >> n;
        p[0] = n / 2;
        ll res = 0;
        rep(i, n / 2, n - 1) p[i] = i + 1;
        p[n - 1] = n / 2 - 1;
        for(int i = n / 2 - 1; i >= 1; i--) p[i] = i - 1;
        rep(i, 0, n - 1) res += max(1LL * i * i, 1LL * (n - 1 - i) * (n - 1 - i));
        cout << res << "\n";
        rep(i, 0, n) cout << p[i] + 1 << " ";
        cout << '\n';
        cout << n - 1 << '\n';
        rep(i, n / 2, n - 1) take(0);
        for(int i = n / 2 - 1; i >= 0; i--) take(n - 1);
    }
}