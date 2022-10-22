#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*

*/

void solve() {
    int n;
    cin >> n;

    int a = (n + 3) / 4;
    int b = n - a;
    for(int i = 0; i < b; i++)
        cout << 9;
    for(int i = 0; i < a; i++)
        cout << 8;

    cout << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}