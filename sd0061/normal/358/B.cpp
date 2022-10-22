#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
#define N 300005
int n;
char s[N] , t[N] , str[N];

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    int i , j , l = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
    {
        s[l] = '<' , s[l + 1] = '3';
        l += 2;
        scanf("%s" , s + l);
        l += strlen(s + l);
    }
    s[l] = '<' , s[l + 1] = '3';
    l += 2;
    scanf("%s" , t);
   //puts(s);
    for (i = 0 , j = 0 ; t[i] && j < l ; ++ i)
        if (t[i] == s[j])
            ++ j;
    puts(j < l ? "no" : "yes");

    return 0;
}