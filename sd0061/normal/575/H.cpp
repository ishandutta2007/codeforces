#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 105;
const int Q = 1e9 + 7;
int n;
int inverse(int x) {
    return x == 1 ? 1 : (LL)(Q - Q / x) * inverse(Q % x) % Q;
}
int p(int x) {
    int res = 1;
    for (int i = 1 ; i <= x ; ++ i)
        res = (LL)res * i % Q;
    return res;
}

void work() {
    //2*(2*n-1)!/(n!*(n-1)!)-1.
    scanf("%d" , &n);
    ++ n;
    LL res = 2 * p(n + n - 1) % Q;
    res *= inverse(p(n)) , res %= Q;
    res *= inverse(p(n - 1)) , res %= Q;
    res += Q - 1 , res %= Q;
    cout << res << endl;
}
int main() {
    work();
    return 0;
}