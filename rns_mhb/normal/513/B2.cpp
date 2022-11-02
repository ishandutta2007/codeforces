#include <bits/stdc++.h>

using namespace std;



#define pb push_back

#define x first

#define y second



template <class T> bool chkmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

const int inf = 1e9;

const ll linf = 1e18;

const int mod = 1e9 + 7;

const double eps = 1e-7;



#define N 55



int n;

ll m;

int a[N];



int main() {

    scanf("%d %I64d", &n, &m);

    m --;

    int e = 0, f = n - 1;

    for (int i = n - 2; i >= 0; i --) {

        if ((m >> i) & 1) {

            a[f--] = n - i - 1;

        }

        else a[e++] = n - i - 1;

    }

    a[e++] = n;

    for (int i = 0; i < n; i ++) printf("%d ", a[i]);

    return 0;

}