#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
#define N 100005
#define LL long long
int n , a[N] , b[N] , q[N];
LL f[N];


int main()
{
   //freopen("~input.txt" , "r" , stdin);
   int i , j , x;
   scanf("%d",&n);
   for (i = 1 ; i <= n ; ++ i)
     scanf("%d",&a[i]);
   for (i = 1 ; i <= n ; ++ i)
     scanf("%d",&b[i]);
   int top , bot;
   q[top = bot = 0] = 1;

   for (i = 2 ; i <= n ; ++ i)
   {
     while (top < bot && (LL)a[i] * (b[q[top]] - b[q[top + 1]]) >= f[q[top + 1]] - f[q[top]])
       ++ top;
     f[i] = f[q[top]] + (LL)a[i] * b[q[top]];
     while (top < bot && (double)(f[i] - f[q[bot]]) * (b[q[bot - 1]] - b[q[bot]]) <= (double)(f[q[bot]] - f[q[bot - 1]]) * (b[q[bot]] - b[i]))
       -- bot;
     q[++ bot] = i;
   }
   cout << f[n] << endl;
   return 0;
}