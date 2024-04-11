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
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 1e6 + 13;
const int M = 998244353;
const int B = 300;
//const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
1
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19

1
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19
*/

int a[N];
int lf[N], rg[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    li n;
    int k;
    cin >> n >> k;

//    if(n < k) {
//        cout << "NO" << endl;
//        return 0;
//    }

    vector<int> a(k, 0);
    for(int i = 0; i < k; i++) {
        a[i] = i + 1;
        n -= i + 1;
    }

    if(n < 0) {
        cout << "NO" << endl;
        return 0;
    }

    int x = n / k;
    for(int i = 0; i < k; i++)
        a[i] += x;
    n %= k;

//    for(int i = 0; i < n % k; i++) {
//        a[k - i - 1]++;
//    }
//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;
//    cout << n << endl;
    bool fl = true;
    while(n > 0) {
        fl = false;
        for(int i = k - 1; i >= 0; i--) {
            x = max(0ll, min(n + a[i], min((i > 0 ? a[i - 1] * 2 : n + a[i]), (i < k - 1 ? a[i + 1] - 1 : n + a[i]))) - a[i]);
//            cout << x << endl;
            a[i] += x;
            n -= x;
            fl |= (x > 0);
        }

        if(!fl) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(auto x : a)
        cout << x << ' ';
    cout << endl;
}