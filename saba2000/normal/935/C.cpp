#include<bits/stdc++.h>
using namespace std;
main()
{

   double R,x,y,p,q;
   cin >> R >> x >> y >> p >> q;
   if(x==p && y == q)
   {
       printf("%.9f %.9f %.9f\n", (x+R/2),y,R/2);
       return 0;
   }
   double l =  sqrt((p-x)*(p-x)+(q-y)*(q-y));
   if(l>R) {
     printf("%.9f %.9f %.9f\n", x,y,R);
       return 0;
   }
   double r = (l + R)/2;
   double sin = (y-q)/l;
   double cos = (x-p)/l;
   printf("%.9f %.9f %.9f\n", (p+r*cos),q+r*sin,r);
}