#include<iostream>
using namespace std;
main()
{long long n,i;
cin>>n;
for (i=1; i*(i+1)/2<n; i++) {}
if((n-i*(i-1)/2)%i==0) cout<<i<<endl; else
cout<<(n-i*(i-1)/2)%i<<endl;
}