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
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++) {
        if(a[l] == b[i])
            l++;
        else if(a[r] == b[i])
            r--;
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}