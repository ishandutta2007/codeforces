#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 5000 + 13;
const int M = 6;
const int A = 21;
const int LOGN = 20;
const int B = 3;//300;

/*
*/


signed main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    li k, d, t;
    cin >> k >> d >> t;

    t *= 2;

    li x = (k + d - 1) / d * d;
    li y = k + x;

    li res = t / y * x;
    li z = t % y;

    if(z <= k * 2) {
        cout << res + z / 2 << (z % 2 == 1 ? ".5" : "") << endl;
    } else {
        cout << res + k + (z - k * 2) << endl;
    }
}