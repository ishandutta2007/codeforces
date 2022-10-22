#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;

int main() {
    scanf("%d" , &n);
    LL sum = 0; int mn = 1 << 30;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        scanf("%d" , &x);
        sum += x;
        if (x & 1)
            mn = min(mn , x);
    }
    if (sum & 1)
        sum -= mn;
    cout << sum << endl;
    return 0;
}