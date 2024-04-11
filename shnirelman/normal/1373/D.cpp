#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int a[N];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    li ans = 0;

    li sum = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 1) {
            sum += a[i];
        } else {
            sum -= a[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        }
    }

//    cout << ans << endl;

    sum = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 1) {
            sum += a[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
        } else {
            sum -= a[i];
        }
    }

//    cout << ans << endl;

    for(int i = 0; i < n; i += 2)
        ans += a[i];

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}