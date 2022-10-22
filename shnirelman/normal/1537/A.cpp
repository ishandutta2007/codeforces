#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    int s = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        s += x;
    }

    if(s == n)
        cout << 0 << endl;
    else if(s > n)
        cout << s - n << endl;
    else
        cout << 1 << endl;
}

int main() {

    int t;
    cin >> t;

    while(t--)
        solve();
}