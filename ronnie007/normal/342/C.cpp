#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
    {
    int r , h ;

    scanf( "%d%d" , &r , &h ) ;

    int ans = h / r * 2;
    h = h % r;

    if (h * 2 < r)
        {
        ans++;
        }
    else if (h * 2 >= sqrt(3) * r)
        {
        ans += 3;
        }
    else
        {
        ans += 2;
        }
    printf("%d\n", ans);
    return 0;
    }