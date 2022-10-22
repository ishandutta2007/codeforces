#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;
const int LOGN = 30;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1 || n % 2 == 1) {
        cout << "Mike" << endl;
        return;
    }

    int mn = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < a[mn])
            mn = i;
    }

    cout << (mn % 2 == 0 ? "Joe" : "Mike") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}