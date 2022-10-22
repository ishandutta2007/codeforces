//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i; j < n; j++) {
            cnt += (s[j] == 'a' ? 1 : -1);
            if(cnt == 0) {
                cout << i + 1 << ' ' << j + 1 << endl;
                return;
            }
        }
    }

    cout << -1 << ' ' << -1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}