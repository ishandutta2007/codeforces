#include <iostream>
using namespace std;
int main ()
{int n,k,p,x,y,m,w=0,z=0,r;
cin>>n>>k>>p>>x>>y;  z=x;
for (int i=0;i<k; i++)
{cin>>m; if (m<y) w++; x-=m;}
if (w>n/2) cout<<-1<<endl;
else { r=((n+1)/2)-w; r--; 
if (x<n-k || r+(n-k-r)*y>x) cout<<-1<<endl; else
{int i; for (i=k; i<n; i++)
{if (w<n/2) {cout<<1<<" "; x--; w++;} else
cout<<y<<" ";}}}
return 0;
}