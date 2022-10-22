//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define x first
#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 6000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    li n, k;
    cin >> n >> k;

    if(k > INF || k * (k + 1) / 2 > n) {
        cout << -1 << endl;
        return 0;
    }

    li res = 1;
    for(li i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * k <= n && i * k * (k + 1) / 2 <= n)
                res = max(res, i);
            if(n / i * k <= n && n / i * k * (k + 1) / 2 <= n)
                res = max(res, n / i);

//            cout << i << ' ' << res << endl;
        }
    }
//return 0;
    for(int i = 1; i < k; i++) {
        cout << res * i << ' ';
        n -= res * i;
    }

    cout << n << endl;
}