#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 5e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

void solve() {
    int n;
    cin >> n;

    cout << n << endl;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = i + 1;

    for(int i = 0; i < n; i++) {
        for(int x : a)
            cout << x << ' ';
        cout << endl;

        if(i < n - 1)
            swap(a[i], a[i + 1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}