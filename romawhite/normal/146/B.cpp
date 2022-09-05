#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <memory.h>

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define PB push_back

using namespace std;

int main()
{
   int a,b;
   cin>>a>>b;
   int c=0;
   while (b){
         c=10*c+b%10;
         b/=10;
   }
   for (int i=a+1;;++i){
       int x=0,y=i;
       while (y){
             if (y%10==4 || y%10==7) x=10*x+y%10;
             y/=10;
       }
       if (x==c) {cout<<i;return 0;}
   }
   return 0;
}