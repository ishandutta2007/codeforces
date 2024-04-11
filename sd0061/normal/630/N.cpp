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
    double a , b , c;
    cin >> a >> b >> c;
    double d = sqrt(b * b - 4 * a * c);
    double l = (-b + d) / (a + a);
    double r = (-b - d) / (a + a);
    if (l < r) swap(l , r);
    printf("%.15f\n%.15f\n" , l , r);
    return 0;
}