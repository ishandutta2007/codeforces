#include<iostream>
using namespace std;
main()
{int n,m,x,y,p,q,k=1000000,a[100000];
cin>>n>>m;
for (int i=0; i<m; i++)
{cin>>x>>y;
if (y-x<k) {k=y-x; p=x; q=y;}
}

cout<<k+1<<endl;
for (int i=0; i<n; i++)
cout<<i%(k+1)<<" ";
return 0;
}