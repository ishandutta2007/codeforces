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
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s;
    }

    int mnf = a[0].f, mxf = a[0].f, mns = a[0].s, mxs = a[0].s;
    for(int i = 0; i < n; i++) {
        mnf = min(mnf, a[i].f);
        mxf = max(mxf, a[i].f);
        mns = min(mns, a[i].s);
        mxs = max(mxs, a[i].s);
    }

    int s = (mxs - mns) * (mxf - mnf);

    cout << (s == 0 ? -1 : s) << endl;
}