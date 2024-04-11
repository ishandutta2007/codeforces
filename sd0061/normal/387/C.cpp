#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 100005
int n ;
char s[N];

bool cmp(int a , int b , int c , int d)
{
    int x = 0;
    for (int i = a , j = c ; i < b && j < d ; ++ i , ++ j)
        if (s[i] != s[j])
        {
            x = s[i] - s[j];
            break;
        }
    return x >= 0;
}

void work()
{
    int i , j , ans = 0;
    scanf("%s" , s);
    n = strlen(s);
    for (i = 0 ; i < n ;)
    {
        j = i , ++ i;
        while (i < n && s[i] == '0')
            ++ i;
        if (j > i - j || (j + j == i && cmp(0 , j , j , i)))
            ++ ans;
        else
            ans = 1;
    }
    printf("%d\n" , ans);
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