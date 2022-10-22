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
const int N = 3e5 + 113;
const int K = 1e5 + 113;
const int M = 998244353;//1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int dif(int a, int b) {
    return sum(a, M - b);
}

/*
*/

int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int r = 0;
    int cur = 0;
    int ans = 0;
    int l1 = 0, r1 = 0;
    for(int l = 0; l < n; l++) {
        while(r < n && (cur < k || a[r] == 1)) {
            cur += (a[r] == 0);
            r++;
        }

        if(r - l > ans) {
            ans = r - l;
            r1 = r;
            l1 = l;
        }

        cur -= (a[l] == 0);
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        cout << (l1 <= i && i < r1 ? 1 : a[i]) << ' ';
    }
    cout << endl;
}