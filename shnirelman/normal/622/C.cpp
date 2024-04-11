//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

/*
*/

int a[N];

int max2[N];
int mn[LOGN][N], mx[LOGN][N];

pii get(int l, int r) {
    int i = max2[r - l];

    return {(a[mn[i][l]] < a[mn[i][r - (1 << i)]] ? mn[i][l] : mn[i][r - (1 << i)]),
            (a[mx[i][l]] > a[mx[i][r - (1 << i)]] ? mx[i][l] : mx[i][r - (1 << i)])};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    max2[1] = 0;
    for(int i = 2; i < N; i++)
        max2[i] = max2[i / 2] + 1;

    for(int i = 0; i < n; i++) {
        mn[0][i] = mx[0][i] = i;
    }

    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j + (1 << i) <= n; j++) {
            mn[i][j] = (a[mn[i - 1][j]] < a[mn[i - 1][j + (1 << i - 1)]] ? mn[i - 1][j] : mn[i - 1][j + (1 << i - 1)]);
            mx[i][j] = (a[mx[i - 1][j]] > a[mx[i - 1][j + (1 << i - 1)]] ? mx[i - 1][j] : mx[i - 1][j + (1 << i - 1)]);
        }
    }

    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        l--;

        pii p = get(l, r);

        cout << (a[p.f] != x ? p.f + 1 : (a[p.s] != x ? p.s + 1 : -1)) << '\n';
    }
}