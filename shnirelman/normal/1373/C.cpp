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

void solve() {
    string s;
    cin >> s;

    int n = s.length();

    vector<int> lf(n + 1, -1);

    int cur = 0;
    int mn = 0;
    li res = 0;
    for(int i = 0; i < n; i++) {
        cur += (s[i] == '+' ? 1 : -1);
        mn = min(mn, cur);

        if(cur < 0 && lf[-cur] == -1) {
            lf[-cur] = i;
            res += i + 1;
        }
    }

    cout << res + n << endl;

//    for(int i = 0; i < n; i++) {
//        cin >> a[i];
//    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}