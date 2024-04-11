#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
#define sqr(x) ((long long)(x)*(x))
int a , b;
char s[N];

bool check(int x , int dx)
{
  if (!x && !dx) return 1;
  if (!dx) return 0;
  if ((long long)x * dx < 0) return 0;
  return abs(x) % abs(dx) == 0;
}

int main()
{
   int i , j , dx , dy , x , y , len;
   scanf("%d%d",&a,&b);
   scanf("%s" , s+1); len = strlen(s + 1);
   dx = dy = 0;
   for (i = 1 ; i <= len ; ++ i)
   {
     if (s[i] == 'U')
        ++ dy;
     if (s[i] == 'D')
        -- dy;
     if (s[i] == 'R')
        ++ dx;
     if (s[i] == 'L')
        -- dx;
   }
   for (i = 0 ; i <= len ; ++ i)
   {
     x = a , y = b;
     for (j = i ; j > 0 ; -- j)
     {
       if (s[j] == 'U')
        -- y;
       if (s[j] == 'D')
        ++ y;
       if (s[j] == 'R')
        -- x;
       if (s[j] == 'L')
        ++ x;
     }
     j = 0;
     if (x == 0 && dx == 0)
     {
       if (check(y , dy))
       {
         puts("Yes");
         return 0;
       }
     }
     if (y == 0 && dy == 0)
     {
       if (check(x , dx))
       {
         puts("Yes");
         return 0;
       }
     }
     if (check(y , dy) && check(x , dx))
        if (abs(y) / abs(dy) == abs(x) / abs(dx))
     {
         puts("Yes");
         return 0;

     }
   }

   puts("No");
   return 0;
}