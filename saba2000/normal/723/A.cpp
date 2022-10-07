#include<iostream>
using namespace std;
main()
{
int a,b,c;
cin>>a>>b>>c;
cout<<max(a,max(b,c))-min(a,min(b,c))<<endl;
}