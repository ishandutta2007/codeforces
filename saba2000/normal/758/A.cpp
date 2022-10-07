#include<iostream>
#include<cmath>
using namespace std;
main()
{int n,s=0,m=0,k;
cin>>n;
for (int i=0; i<n; i++)
{cin>>k;
m=max(m,k);
s+=k;
}
cout<<m*n-s<<endl;
}