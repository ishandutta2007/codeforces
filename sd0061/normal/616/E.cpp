#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 600005;
const int Q = 1e9 + 7;
void work() {

    LL n , m , res = 0;
    cin >> n >> m;
    res += (n % Q) * (m % Q) % Q;
    res %= Q;
    LL delta = 0;
    for (LL i = 1 , x ; i <= n && i <= m ; i = x + 1) {
        x = min(m , n / (n / i));
        delta += (LL)((n / i) % Q) * ((i + x) % Q) % Q * ((x - i + 1) % Q) % Q * (Q - Q / 2) % Q;
        delta %= Q;
    }
    res += Q - delta;
    res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}