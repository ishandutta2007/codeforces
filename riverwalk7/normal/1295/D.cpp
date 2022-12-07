#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int T; ll a, m, x, cur, cur2;
int main()
{
   cin>>T;
   for(int i=0; i<T; i++)
   {
       cin>>a>>m;
       x = m/__gcd(m, a);
       cur = x; cur2 = x;
       for(int j=2; j<=sqrt(x); j++)
       {
           if(cur % j == 0)
           {
               cur2 = cur2*(j-1)/j;
               while(cur % j == 0)
               {
                   cur /= j;
               }
           }
       }
       if(cur > sqrt(x))
       {
           cur2 = cur2/cur*(cur-1);
       }
       cout<<cur2<<endl;
   }
}