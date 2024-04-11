#include <iostream>
#include <cmath>
using namespace std;
int d[100009],h[100009],n,m,a,b,c,k,hma,hmi;
int main ()
{
cin>>n>>m;
for (int i=0; i<m; i++)
cin>>d[i]>>h[i];
hma=h[0]+d[0]-1;
for (int i=0; i<m-1; i++)
{hma=max(hma,(d[i+1]-d[i]+h[i]+h[i+1])/2);
if (abs(h[i]-h[i+1])>d[i+1]-d[i]) k=1;}

hma=max(hma,h[m-1]+n-d[m-1]);
if (k==1) cout<<"IMPOSSIBLE"<<endl;
else cout<<hma<<endl;
return 0;

}