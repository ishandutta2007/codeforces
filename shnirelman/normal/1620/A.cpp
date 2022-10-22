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
const int N = 2e5 + 113;
const int K = 1e5 + 113;
const int M = 1e9 + 7;
const int A = 26;

/*
*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += (s[i] == 'N');

    if(cnt == 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}