#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define M 2000005
#define N 100005
int a , b , c , d , x , y;

void work()
{
    scanf("%d:%d\n%d:%d\n",&a,&b,&c,&d);
    x = a * 60 + b;
    y = c * 60 + d;
    if (x < y)
        x += 60 * 24;
    x -= y;
    printf("%02d:%02d\n" , x / 60 , x % 60);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //while (~scanf("%d",&n))
        work();
    return 0;
}