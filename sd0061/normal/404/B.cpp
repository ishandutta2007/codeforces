#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 305

LL a , d , n;

void work()
{
    double r;
    scanf("%lf",&r) , a = 1e4 * r + 1e-1;
    scanf("%lf",&r) , d = 1e4 * r + 1e-1;
    cin >> n ;
    for (int i = 1 ; i <= n ; ++ i) {
        LL x = d * i % (a << 2);
        if (x < a) {
            printf("%f %f\n" , x / 1e4 , 0.0);
        } else if (x < 2 * a) {
            printf("%f %f\n" , a / 1e4 , (x - a) / 1e4);
        } else if (x < 3 * a) {
            printf("%f %f\n" , (a - (x - a - a)) / 1e4 , a / 1e4);
        } else {
            printf("%f %f\n" , 0.0 , (a - (x - a - a - a)) / 1e4);
        }
    }
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}