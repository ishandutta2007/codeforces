#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 205;
const int Q = 1e9 + 7;

int n , m;

bool check(int h) {
    int s6 = h / 6 , s2 = h / 2 - s6 , s3 = h / 3 - s6;
    int nn = n , mm = m;
    nn -= min(nn , s2);
    mm -= min(mm , s3);
    int d = min(nn , s6);
    nn -= d , s6 -= d;
    d = min(mm , s6);
    mm -= d , s6 -= d;
    return nn == 0 && mm == 0;
}

int main() {

    cin >> n >> m;
    int l = 0 , r = 1e9 , mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n" , r);
    return 0;
}