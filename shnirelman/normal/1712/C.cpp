#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 1e6 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);


void solve() {
    int n;
    cin >> n;

    vector<int> a(n), lst(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        lst[a[i]] = i;
    }

    int lf = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] > a[i + 1]) {
            lf = i + 1;
            break;
        }

    }

//    cout << lf << endl;

    vector<bool> used(n, false);
    int ans = 0;
    int mx = -1;
    for(int i = 0; i <= n; i++) {
        //cout << i
        if(mx <= i - 1 && i >= lf) {
            cout << ans << endl;
            return;
        }

        if(!used[a[i]]) {
            used[a[i]] = true;
            ans++;
            mx = max(mx, lst[a[i]]);
        }
    }

    assert(false);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}