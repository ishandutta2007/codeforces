#define _GLIBCXX_DEBUG
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
const int N = 3e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

int xr[N];

void solve() {
    int a, b;
    cin >> a >> b;

//    int x = xr[a - 1];
    if(xr[a - 1] == b)
        cout << a << endl;
    else if(xr[a] == b)
        cout << a + 2 << endl;
    else
        cout << a + 1 << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    for(int i = 1; i < N; i++) {
        xr[i] = xr[i - 1] ^ i;
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}