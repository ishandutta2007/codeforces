#include<iostream>
using namespace std;
main()
{long long n,p=0,t=0;
cin>>n;
int k=n%2520;
for (int i=1; i<=2520; i++)
{for (int j=2; j<=10; j++)
if(i%j==0) {p++; if(i<=k)t++; break;}
}
cout<<n-p*(n/2520)-t<<endl;
}