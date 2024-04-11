//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

//const li INF = 2e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
//const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

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

/*
3 5 0 0 5
1 3 1

*/


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, A, cf, cm;
    li m;
    cin >> n >> A >> cf >> cm >> m;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f;
        a[i].s = i;
    }

    sort(a.begin(), a.end());

    vector<li> s(n + 1, 0);
    for(int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i].f;
    }

    int j = 0;
    li ans = -1;
    li resi = 0, resx = 0, resj = 0;

    if(n * 1ll * A - s[n] <= m) {
        ans = n * 1ll * cf + A * 1ll * cm;
        resi = 0;
        resx = A;
        resj = -1;
    }
    for(int i = 0; i <= n; i++) {
        if((n - i) * 1ll * A - s[n] + s[i] > m)
            continue;

        li x = m - ((n - i) * 1ll * A - s[n] + s[i]);

        while(j + 1 < i) {
            if(a[j + 1].f * 1ll * (j + 1) - s[j + 1] > x)
                break;
            j++;
        }

        li b = min(A * 1ll, (x + s[j + 1]) / (j + 1));

        if(b * cm + (n - i) * 1ll * cf > ans) {
            ans = b * cm + (n - i) * 1ll * cf;
            resi = i;
            resx = b;
            resj = j;
        }
    }

    cout << ans << endl;

    vector<int> b(n, 0);
    for(int i = resi; i < n; i++) {
        b[a[i].s] = A;
        m -= A - a[i].f;
    }

    for(int i = 0; i <= resj; i++) {
        b[a[i].s] = resx;
    }

    for(int i = resj + 1; i < resi; i++)
        b[a[i].s] = a[i].f;

    for(auto x : b)
        cout << x << ' ';
}