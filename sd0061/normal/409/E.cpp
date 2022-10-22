#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
void work()
{
    double ans;
    cin >> ans;
    for (int i = 1 ; i <= 10 ; ++ i)
        for (int j = 1 ; j <= 10 ; ++ j) {
            double a = i * 0.5 , b = j;
            double res = a * b / sqrt(a * a + b * b);
            if (fabs(res - ans) < 1e-6) {
                printf("%d %d\n" , i , j);
                return;
            }
        }
}


int main()
{
    //freopen("~inputs.txt" , "r" , stdin);
    //int _; scanf("%d\n",&_); while (_ --)
        work();
    return 0;
}