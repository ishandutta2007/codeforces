#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 1000002;
char str[N] , t[N];
int f1 , f6 , f8 , f9;
int p;
void work()
{
    int i , j , sum = 0;
    scanf("%s" , str);
    for (i = 0 ; str[i] ; ++ i)
    {
        int x = str[i] - '0';
        if (x == 1 && !f1) {f1 = 1 ; continue;}
        if (x == 6 && !f6) {f6 = 1 ; continue;}
        if (x == 8 && !f8) {f8 = 1 ; continue;}
        if (x == 9 && !f9) {f9 = 1 ; continue;}
        sum *= 10 , sum += x , sum %= 7 , t[p ++] = str[i];

    }
    j = 1;
    for (i = 0 ; i < p ; ++ i) j *= 10 , j %= 7;

    if ((6 * j + sum) % 7 == 0)
        printf("1896");
    if ((0 * j + sum) % 7 == 0)
        printf("1869");
    if ((1 * j + sum) % 7 == 0)
        printf("1968");
    if ((2 * j + sum) % 7 == 0)
        printf("6981");
    if ((3 * j + sum) % 7 == 0)
        printf("6198");
    if ((4 * j + sum) % 7 == 0)
        printf("1698");
    if ((5 * j + sum) % 7 == 0)
        printf("1986");
    puts(t);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
//    while (scanf("%d%d",&n,&k) , n || k)
        work();
    return 0;
}