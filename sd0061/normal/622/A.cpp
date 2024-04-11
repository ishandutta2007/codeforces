#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 998244353;

void work() {
    LL n;
    cin >> n;
    LL l = 0 , r = 1e8 , m;
    while (l < r) {
        m = l + r + 1 >> 1;
        LL v = m * (m + 1) / 2;
        if (v < n)
            l = m;
        else
            r = m - 1;
    }
    LL v = l * (l + 1) / 2;    
    cout << n - v << endl;
}
 
int main() {
    work();
    return 0;
}