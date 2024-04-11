#include <iostream>
#include <cmath>
using namespace std;
int main ()
{int x,a,b,d[10]={0},ans=0;
 cin>>x;

for (int i=x; i>0; i/=10)
d[i%10]=1;
for (int i=1; i<=sqrt((double)x); i++)
if (x%i==0){a=i; b=x/i;
 for (int i=a; i>0 ; i/=10)
if (d[i%10]==1) {ans++;  break;
}
for (int i=b; (i>0 && (double)b!=sqrt((double)x) ); i/=10)
if (d[i%10]==1) {ans++; break;
} }
cout<<ans<<endl;
return 0;
}