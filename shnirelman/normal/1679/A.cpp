#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 2e5 + 13;
const int K = 9;
const int M = 2e6 + 9;
const int LOGN = 20;

void solve() {
    li n;
    cin >> n;

    if(n % 2 != 0 || n == 2) {
        cout << -1 << endl;
        return;
    }

//    if(n % 6 == 0)
//        cout << n / 6;
//    else if(n % 6 == 2)
//        cout << n / 6 + 1;
//    else
//        cout << n / 6 + 1;
//    cout << ' ';


    cout << (n + 5) / 6 << ' ' << n / 4 << endl;

//    cout << (n + 2) / 4 << ' ' << n / 6 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}