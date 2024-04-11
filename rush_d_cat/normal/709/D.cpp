#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;
ll a00, a01, a10, a11;
ll m = -1, n = -1, i, l = 0, r = 0, mid = -1;
ll num[1000000 + 10], tot = 0;
int main()
{
    cin >> a00 >> a01 >> a10 >> a11;
    for(i = 1; i <= 1000000; i++)
    {
        if(i * (i - 1) / 2 == a00) m = i;
        if(i * (i - 1) / 2 == a11) n = i;
    }
    if(a01 == 0 && a10 == 0)
    {
        if(a00 == 0) m = 0;
        else n = 0;
    }
    if(m * (m - 1) / 2 != a00 || n * (n - 1) / 2 != a11) {cout <<"Impossible"; return 0;}
    if((a01 + a10) != m * n){cout << "Impossible";return 0;}
    while(m + n)
    {
        if(a01 >= n)
        {
            a01 -= n;
            m --;
            printf("0");
        } else {
            a10 -= m;
            n --;
            printf("1");
        }
    }
}