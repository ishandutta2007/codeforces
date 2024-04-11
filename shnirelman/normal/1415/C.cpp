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
    int n, p, k;
    cin >> n >> p >> k;

    p--;

    string a;
    cin >> a;

    int x, y;
    cin >> x >> y;

    vector<int> s(k, 0);
    for(int i = p; i < n; i++) {
        s[i % k] += (a[i] == '0');
    }

    int ans = INF;
    for(int i = 0; i < n - p; i++) {
        ans = min(ans, s[(i + p) % k] * x + i * y);
        if(a[i + p] == '0')
            s[(i + p) % k]--;
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