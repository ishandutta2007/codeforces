#include<iostream>
using namespace std;
int q,t,p,ans,n;
main()
{cin>>n;
if(n%2==1) cout<<0<<endl; else
if(n%4==0)
cout<<n/4-1<<endl;
else cout<<n/4<<endl;
}