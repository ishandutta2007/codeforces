#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
    ll g = __gcd(ta, tb);
    ll len2 = rb - lb + 1;
    lb %= ta;
    ll len = la - lb;
    if (len < 0) {
        len += ta;
    }
    ll jump = 0;
    if (len) {
        jump = (len - 1) / g + 1;
    }
    ll pos = (lb + jump * g) % ta;
    if (pos < la || pos > ra) {
        return 0;
    } else {
        return min(ra - pos + 1, len2);
    }
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll la, ra, ta;
    cin >> la >> ra >> ta;
    ll lb, rb, tb;
    cin >> lb >> rb >> tb;
    cout << max(solve(la, ra, ta, lb, rb, tb), solve(lb, rb, tb, la, ra, ta));
//    ll g = __gcd(ta, tb);
//    ll len2 = rb - lb + 1;
//    lb %= ta;
//    ll len = la - lb;
//    if (len < 0) {
//        len += ta;
//    }
//    cout << len << "\n";
//    ll jump = 0;
//    if (len) {
//        jump = (len - 1) / g + 1;
//    }
//    cout << lb << " " << la << " " << ra << "\n";
//    ll pos = (lb + jump * g) % ta;
//    if (pos < la || pos > ra) {
//        cout << "0\n";
//    } else {
//        cout << min(ra - pos + 1, len2);
//    }
}