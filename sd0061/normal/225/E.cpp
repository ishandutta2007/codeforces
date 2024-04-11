#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int f[100005];

int ans[] = {0 , 2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583, 25964951};
long long Q = 1e9 + 7;
int power(int b)
{
    long long a = 2 , res = 1;
    while (b)
    {
        if (b & 1)
            res *= a , res %= Q;
        a *= a , a %= Q , b >>= 1;
    }
    return res;
}


void work()
{
    int n;
    scanf("%d",&n);
    printf("%d\n" , (power(ans[n] - 1) + Q - 1) % Q);
}

int main()
{
    //while (~scanf("%s%s", a, b))
        work();
    return 0;
}