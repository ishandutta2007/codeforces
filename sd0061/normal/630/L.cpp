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
    int a[5] = {};
    for (int i = 0 ; i < 5 ; ++ i)
        a[i] = n % 10 , n /= 10;
    int m = a[4] * 10000 + a[2] * 1000 + a[0] * 100 + a[1] * 10 + a[3];
    int res = 1;
    for (int i = 0 ; i < 5 ; ++ i)
        res = (LL)res * m % 100000;
    printf("%05d\n" , res);
    return 0;
}