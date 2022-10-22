//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 20000 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;

mt19937 rnd(time(0));

/*

*/

int sum(int a, int b) {
    a += b;
    if(a < 0)
        return a + M;
    else if(a >= M)
        return a - M;
    else
        return a;
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

int pow2(int n, int k) {
    if(k == 0)
        return 1;
    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);
    return(k % 2 == 1 ? mul(pw, n) : pw);
}

map<int, int> dp;

vector<pii> calc(vector<int>& p, int i, int cur, int ml) {
    if(i == p.size()) {
        return vector<pii>(1, {cur, ml});
    }

    vector<pii> r1 = calc(p, i + 1, cur, ml);
    vector<pii> r2 = calc(p, i + 1, cur * p[i], -ml);
    for(auto x : r2)
        r1.push_back(x);
    return r1;
}

int get(int y) {
    if(dp.count(y))
        return dp[y];

    if(y == 1)
        return 1;

//    cout << y << endl;

    int y1 = y;
    vector<int> p;
    for(int i = 2; i * i <= y; i++) {
//        cout << i << ' ' << y << endl;
        if(y % i == 0) {
            p.push_back(i);
            while(y % i == 0)
                y /= i;
        }
    }
    if(y > 1)
        p.push_back(y);
    y = y1;

    auto dv = calc(p, 0, 1, 1);

    int res = 0;//pow2(2, y - 1);
    for(auto pr : dv)  {
        res = sum(res, pow2(2, y / pr.f - 1) * pr.s);
//        cout << res << ' ' << pr.f << ' ' << pr.s << endl;
//        res = sum(res, get(y / pr.f) * pr.s);
    }

    dp[y] = res;
//    cout << y << ' ' << dp[y] << endl;
    return dp[y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;

    if(y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    cout << get(y / x) << endl;
}