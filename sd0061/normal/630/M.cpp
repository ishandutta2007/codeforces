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
const int N = 100005;

int main() {
    LL n;
    cin >> n;
    n %= 360;

    int res = 1 << 30 , t = 0;
    for (int i = 0 ; i <= 20 ; ++ i) {
        int m = (n - 90 * i) % 360;
        m = (m + 360) % 360;
        int p = min(m , 360 - m);
        if (p < res) {
            res = p;
            t = i;
        }
    }
    cout << t << endl;
    
    return 0;
}