#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 100005
#define LL long long
int n , m , f[N] , t;


int main()
{
  //freopen("~input.txt","r",stdin);
   LL n , d , m , l;

   cin >> n >> d >> m >> l;
   LL k = 0 , x = 0 , i = 0;
   while (1)
   {
     LL t = (l - x) / d;
     i += t , x += t * d , k += x / m , x %= m;
     if (k >= n || x > l)
     {
       cout << i * d << endl;
       return 0;
     }
     t = 1 , i += t , x += t * d , k += x / m , x %= m;
     if (k >= n || x > l)
     {
       cout << i * d << endl;
       return 0;
     }
   }
   return 0;
}