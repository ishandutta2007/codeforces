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
const int N = 1e5 + 13;
const int LOGN = 20;
const int K = 11;
const int M = 1e9 + 7;
const int A = 26;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    if(k % 2)
        return mul(pw, n);
    else
        return pw;
}
/*
*/

int n;
int a[N], b[N];

bool is(int x) {
    for(int i = 1, j = 0; j < x; i += 2, j++) {
        b[i] = a[j];
    }

    for(int j = n - 1, i = x * 2; i >= 0; j--, i -= 2) {
        b[i] = a[j];
    }

    for(int i = x * 2 + 1, j = x; i < n; i++, j++) {
        b[i] = a[j];
    }

    int cnt = 0;
    for(int i = 1; i < n - 1; i++) {
        cnt += (b[i] < b[i - 1] && b[i] < b[i + 1]);
    }

//    cout << "is " << x << ' ' << cnt << endl;
//    for(int i = 0; i < n; i++) {
//        cout << b[i] << ' ';
//    }
//    cout << endl;

    return (cnt >= x);
}

void solve() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, r = (n - 1) / 2 + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;

        bool res = is(m);

//        cout << l << ' ' << m << ' ' << r << ' ' << res << endl;


        if(res)
            l = m;
        else
            r = m;
    }

    cout << l << endl;

    is(l);

    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}