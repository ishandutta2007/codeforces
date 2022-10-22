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
    double pi = acos(-1);
    double l , res = 0;;

    for (int i = 3 ; i <= 5 ; ++ i) {
        cin >> l;
        double x = l / 2 / sin(pi / i);
        double h = sqrt(l * l - x * x);
        double S = x * x / 2 * i * sin((pi + pi) / i);
        res += S * h / 3;
    }
    printf("%.15f\n"  , res);
    
    
    return 0;
}