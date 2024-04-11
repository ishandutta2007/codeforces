#include <iostream>
using namespace std;
int main ()
{int an=0,n,k[100009]={0};
cin>>n;
for (int i=0; i<n; i++)
{int p; cin>>p; 
k[p]++;
}
for (int i=1; i<100000; i++)
if (k[i]>1 && k[i]!=0) {k[i+1]+=k[i]-1; an+=k[i]-1; k[i]=1;}
cout<<an<<endl;
return 0;
}