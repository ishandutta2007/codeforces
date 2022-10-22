#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int M = 1e9 + 7;
const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int A = 26;
const int B = 300;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = INF;
    for(int i = 1; i <= 100; i++) {
        int res = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] != i) {
                res++;
                j += k - 1;
            } else {

            }
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}