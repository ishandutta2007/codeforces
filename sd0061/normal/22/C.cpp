#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 100005
#define ULL unsigned long long
int n , m , f[N] , t;


int main()
{
  //freopen("~input.txt","r",stdin);
   int i , j;
   cin >> n >> m >> t;
   if (m < n - 1) {puts("-1");return 0;}
   for (i = 1 ; i <= n ; ++ i) f[i] = i;
   swap(f[n - 1] , f[t]);
   //m -= n - 1;
   if (m > (long long)(n - 1) * (n - 2) / 2 + 1)
     puts("-1");
   else
   {
     for (i = 1 ; i < n ; ++ i)
       printf("%d %d\n" , f[i] , f[i + 1]);
     m -= n - 1;
     for (i = 1 ;m && i <= n - 1 ; ++ i)
        for (j = i + 2 ; m && j <= n - 1 ; ++ j)
           -- m , printf("%d %d\n" , f[i] , f[j]);
   }
   return 0;
}