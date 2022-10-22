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

    int m = n - 1;

    vector<int> a(n);
    for(int i = n - 1; i >= 0; ) {
        int x = int(sqrt(i) + 0.1);

        if(x * x < i)
            x++;

//        cout << i << ' ' << x * x << endl;

        while(x * x - i <= m) {
            a[i] = x * x - i;
            i--;
        }

        m = i;
    }

    for(int x : a)
        cout << x << ' ';
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