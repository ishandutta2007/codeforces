#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int A = 26;
const int B = 400;

void solve() {
    int n;
    cin >> n;

    vector<int> a;

    for(int i = 1; i < n - 2; i++)
        a.push_back(i + 1);
    a.push_back(1);
    a.push_back(n - 1);
    a.push_back(n);

    int x = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > x)
            x += a[i];
        else
            x = 0;
    }

    if(x == n * 2 - 1) {
        for(int y : a)
            cout << y << ' ';
        cout << endl;
        return;
    }

    swap(a[0], a[1]);

    for(int y : a)
        cout << y << ' ';
    cout << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}