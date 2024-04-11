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
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 2000005;

int main() {
    LL l , r , a , b , c;
    cin >> l >> r;
    for (a = l ; a <= r ; ++ a)
        for (b = a + 1 ; b <= r ; ++ b)
            for (c = b + 1 ; c <= r ; ++ c)
                if (__gcd(a , b) == 1 && __gcd(b , c) == 1 && __gcd(a , c) != 1) {
                    cout << a << ' ' << b << ' ' << c << endl;
                    return 0;
                }
    puts("-1");
    return 0;
}