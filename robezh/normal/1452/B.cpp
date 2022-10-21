#include <bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        ll sum = 0;
        int mx = 0;
        rep(i, 0, n) cin >> a[i], mx = max(a[i], mx), sum += a[i];
        cout << max((sum + n - 2) / (n - 1) * (n - 1) - sum, 1LL * mx * (n - 1) - sum) << '\n';
    }


}