#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 100005;
int a , b;
void work() {
    cin >> a >> b;
    double res = 1e60;
    int p = a - b;
    if (p >= 0) {
        if (p == 0)
            res = min(res , (double)b);
        else {
            int k = p / 2 / b;
            if (k > 0) {
                double q = p / 2.0 / k;
                res = min(res , q);
            }
        }
    }
    p = a + b;
    if (p >= 0) {
        if (p == 0)
            res = min(res , (double)b);
        else {
            int k = p / 2 / b;
            if (k > 0) {
                double q = p / 2.0 / k;
                res = min(res , q);
            }
        }
    }
    if (res > 1e50)
        puts("-1");
    else
        printf("%.10f\n" , res);
}

int main() {
    work();
    return 0;
}