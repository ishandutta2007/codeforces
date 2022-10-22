#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 1e6 + 13;

vector<int> d[N];

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<char> is(n + 3, false);
    li ans = 0;
    for(int i = 1; i <= n; i++) {
//        cout << s[i - 1] << endl;
        if(s[i - 1] == '0') {
            is[i] = true;
            for(int x : d[i])
                if(is[x]) {
                    ans += x;
//                    cout << x << endl;
                    break;
                }

        } else {
            for(int x : d[i])
                is[x] = false;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i)
            d[j].push_back(i);
    }

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}