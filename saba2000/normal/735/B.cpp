#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long double n,a,b,c[100009],s1,s2;
main()
{cin>>n>>a>>b;
for (int i=0 ;i<n ;i++)
cin>>c[i];
sort(c,c+(int)n);
for (int i=n-1; i>n-1-min(a,b); i--)
s1+=c[i];
for (int i=n-1-min(a,b); i>n-1-max(a,b)-min(a,b); i--)
s2+=c[i];
cout.precision(9);
cout<<s1/min(a,b)+s2/max(a,b)<<endl;
//system("pause");
}