#include<iostream>
#include<cmath>
using namespace std;
main()
{int n; string s,p="",k;
cin>>n;
cin>>s;
for (int i=n-2;i>=0; i-=2)
p+=s[i];
for (int i=(n+1)%2
; i<n; i+=2)
p+=s[i];
cout<<p<<endl;
return 0;
}