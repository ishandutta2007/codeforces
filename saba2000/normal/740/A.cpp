#include<iostream>
using namespace std;
main()
{long long n,a,b,c;
cin>>n>>a>>b>>c;
if (n%4==3) cout<<min(b+c,min(a,c*3))<<endl;
if (n%4==0) cout<<0<<endl;
if (n%4==2) cout<<min(min(2*a,b),2*c)<<endl;
if (n%4==1) cout<<min(a+b,min(3*a,c))<<endl;
return 0;
}