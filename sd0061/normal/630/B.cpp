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
    int n ; double res , a;
    cin >> res >> n;
    a = 1.000000011;
    while (n) {
        if (n & 1)
            res = res * a ;
        a = a * a , n >>= 1;
    }
    printf("%.15f\n" , res);
    return 0;
}