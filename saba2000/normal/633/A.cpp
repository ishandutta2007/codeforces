#include<iostream>
using namespace std;
main()
{int a,b,c;
cin>>a>>b>>c;
for (int i=0; i<=c; i++)
if (c-a*i>=0 && (c-a*i)%b==0) {cout<<"Yes"<<endl; return 0;}
cout<<"No"<<endl;

}