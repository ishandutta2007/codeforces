#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 500 + 13;
const int LOGN = 10;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

/*
4
1 2 3 4
1
1 5
*/

void solve() {
    string s;
    cin >> s;

    int fir = -1, lst = -1, cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            cnt++;
            if(fir == -1)
                fir = i;
            lst = i;
        }
    }

    cout << (fir == -1 ? 0 : lst - fir + 1 - cnt) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}