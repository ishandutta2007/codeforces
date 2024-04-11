#include <iostream>
using namespace std;
int main ()
{int n,p[100]={0},a=0;
char k;
cin>>n;
for (int i=0; i<n; i++)
{cin>>k;
if (k=='*') p[i]++;
}
for (int i=1; i<=n/4; i++)
for (int j=0; j<n-i*4; j++)
if (p[j]==1 && p[j+i]==1 && p[j+2*i]==1 && p[j+3*i]==1 && p[j+4*i]==1) a=1;
if (a==0) cout<<"no"; else cout<<"yes";
}