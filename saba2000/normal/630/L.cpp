#include<iostream>
using namespace std;
main()
{long long n;
cin>>n;
long long a=n/10000,b=n/1000%10,c=n/100%10,d=n/10%10,e=n%10;
n=a*10000+c*1000+e*100+d*10+b;
long long p=n*n;
p%=100000;
p=p*n;
p%=100000;
 p=p*n;
p%=100000;
 p=p*n;
p%=100000;
if(p<10000) cout<<0;
if(p<1000) cout<<0;
if(p<100) cout<<0;
if(p<10) cout<<0;
cout<<p<<endl;

}