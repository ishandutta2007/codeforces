#include <iostream>
using namespace std;
int main ()
{int n,m[1009]={0},p,k=0,q[1009]={0}; cin>>n;
for (int i=0; i<n; i++)
{cin>>p; k=max(p,k);
if (m[p]>0) q[p]=i+1; else
m[p]=i+1;
}
for (int i=1; i<=k; i++)
for (int j=1; j<i; j++)
if (m[i]!=0 && m[j]!=0 && m[i-j]!=0 && m[i-j]!=m[j] && i>j) {cout<<m[i]<<" "<<m[j]<<" "<<m[i-j]<<endl; return 0;}else if (m[i]!=0 && i%2==0 && m[i/2]>0 && q[i/2]>0){ cout<<m[i]<<" "<<m[i/2]<<endl<<q[i/2]<<endl; return 0;}

cout<<-1<<endl;
return 0;
}