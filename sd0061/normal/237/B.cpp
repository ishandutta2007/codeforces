#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 55
#define LL long long
int n , a[N][N] , c[N];
pair<int , int> f[N * N];
int xx[N * N] , yy[N * N] , X[N * N] , Y[N * N] , sum;
int main()
{
   int i , j , k , l , x = 1;
   scanf("%d",&n);
   for (i = 0 ; i < n ; ++ i)
     scanf("%d",&c[i]);
   for (i = 0 ; i < n ; ++ i)
     for (j = 0 ; j < c[i] ; ++ j)
       scanf("%d",&a[i][j]);
   for (i = 0 ; i < n ; ++ i)
     for (j = 0 ; j < c[i] ; ++ j , ++ x) if (a[i][j] != x)
     {
       for (k = 0 ; k < n ; ++ k)
         for (l = 0 ; l < c[k] ; ++ l)
           if (a[k][l] == x)
             goto PA;
       PA:
       swap(a[i][j] , a[k][l]);
       xx[sum] = i , yy[sum] = j , X[sum] = k , Y[sum ++] = l;
     }
   printf("%d\n" , sum);
   for (i = 0 ; i < sum ; ++ i)
        printf("%d %d %d %d\n" , xx[i] + 1 , yy[i] + 1, X[i] + 1 , Y[i] + 1);
   return 0;
}