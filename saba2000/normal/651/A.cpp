#include<iostream>
using namespace std;
main()
{int a,b,ans=0;
cin>>a>>b;
if (a<2 && b<2) {cout<<0<<endl; return 0;}
while(a>0 && b>0)
{if(a>b){a-=2; b+=1;}
else {a+=1; b-=2;}
ans++;}
cout<<ans<<endl;
}