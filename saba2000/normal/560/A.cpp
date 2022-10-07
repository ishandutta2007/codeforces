#include<iostream>
using namespace std;
main()
{int n,s=1,a;
cin>>n;
for (int i=0; i<n; i++)
{cin>>a; if (a==1) s=-1;}
cout<<s<<endl;
}