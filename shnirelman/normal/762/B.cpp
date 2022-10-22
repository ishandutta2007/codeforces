#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int n;
    cin >> n;

    vector<pii> x(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> x[i].f >> s;

        x[i].s = (s[0] == 'U');
    }

    sort(x.begin(), x.end());

    li res = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(x[i].s) {
            if(a > 0) {
                ans++;
                res += x[i].f;
                a--;
            } else if(c > 0) {
                ans++;
                res += x[i].f;
                c--;
            }
        } else {
            if(b > 0) {
                ans++;
                res += x[i].f;
                b--;
            } else if(c > 0) {
                ans++;
                res += x[i].f;
                c--;
            }
        }
    }

    cout << ans << ' ' << res << endl;
}