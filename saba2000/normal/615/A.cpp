#include<iostream>
using namespace std;
int n,m,f[100];
main()
{int x,a;
cin>>n>>m;
for(int i=0; i<n; i++)
{cin>>x;
for (int j=0; j<x; j++)
{cin>>a; f[a-1]=1;}
}
for (int i=0; i<m ; i++)
if (f[i]==0) {cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl;

}