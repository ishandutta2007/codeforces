#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 200005;
LL a , b;
LL Q = 1e9 + 7;
void work() {
    cin >> a >> b;
    LL ans = 0;
    for (LL i = 1 ; i < b ; ++ i) {
        ans += a * i % Q , ans %= Q;
        ans += (a * (a + 1) / 2) % Q * b % Q * i % Q , ans %= Q;
    }
    cout << ans << endl;
}

int main() {
    work();
    return 0;
}