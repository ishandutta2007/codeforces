#include<iostream>
using namespace std;
main()
{int n,m,a,b;
cin>>n>>m;
a=1; b=100000000;
while (a<b)
{int c=(a+b)/2;
int p=c/2-c/6,q=c/3-c/6,t=c/6;
if (p+q+t>=m+n && p+t>=n && q+t>=m) b=c;
else a=c+1;}
cout<<a<<endl;
}