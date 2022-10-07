#include<iostream>
using namespace std;
main()
{long long n;
cin>>n;
long long a=n*(n-1)*(n-2)*(n-3)*(n-4)/120;
long long b=n*(n-1)/2*(n-2)/3*(n-3)/4*(n-4)/5*(n-5)/6;
long long c=n*(n-1)/2*(n-2)/3*(n-3)/4*(n-4)/5*(n-5)/6*(n-6)/7;
cout<<a+b+c<<endl;
}