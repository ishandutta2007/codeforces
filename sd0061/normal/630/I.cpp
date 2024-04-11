#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 105;
int main() {
    int n;
    cin >> n;
    int m = n + n - 2;
    LL res = 0;
    for (int i = 1 ; i + n - 1 <= n + n - 2 ; ++ i) {
        int p = n + n - 2 - n + 1 , q = 0;
        if (i > 1) -- p , ++ q;
        if (i + n - 1 < n + n - 2) -- p , ++ q;
        LL x = (1LL << p + p);
        while (q --) x *= 3;
        res += x;
    }
    cout << res << endl;
    return 0;
}