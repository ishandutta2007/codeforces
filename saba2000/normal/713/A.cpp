#include<iostream>
#include<map>
using namespace std;
map <long long,int> m;
long long t,n,a,s,k;
char c;
main()
{cin>>t;
for (int i=0; i<t; i++)
{cin>>c>>n;
if (c!='?'){
a=n; s=0; k=1;
while(a>0)
{s+=k*((a%10)%2);
a/=10;
k*=10;}
if (c=='+') m[s]++; else m[s]--;}
else
cout<<m[n]<<endl;
}
}