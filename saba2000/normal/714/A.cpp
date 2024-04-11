#include<iostream>
using namespace std;
main()
{long long  a,b,c,d,k;
cin>>a>>b>>c>>d>>k;
if (k>=max(c,a) && k<=min(b,d)) cout<<max((long long) 0,min(b,d)-max(c,a))<<endl;
else cout<<max((long long)0,min(b,d)-max(c,a)+1)<<endl;

}