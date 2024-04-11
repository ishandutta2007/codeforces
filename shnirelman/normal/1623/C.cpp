#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 2e18 + 13;
const int N = 2e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

/*

*/

int n;
int a[N];
int b[N];

bool is(int x) {
    for(int i = 0; i < n; i++)
        b[i] = a[i];

    for(int i = n - 1; i >= 2; i--) {
//        cout << i << ' ' << b[i] << endl;
        if(b[i] < x)
            return false;
        int d = min(a[i], b[i] - x) / 3;

        b[i - 1] += d;
        b[i - 2] += d * 2;
    }

    return (b[0] >= x && b[1] >= x);
}

void solve() {

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = INF;
    while(r - l > 1) {
        int m = (l + r) / 2;

//        cout << l << ' ' << m << ' ' << r << ' ' << is(m) << endl;

        if(is(m))
            l = m;
        else
            r = m;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}