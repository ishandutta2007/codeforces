#include<iostream>
#include<cmath>
using namespace std;
long long cv(string s)
{long long an=0;
for (long long i=0; i<s.size(); i++)
an=an*10+(s[i]-'0');
return an;
}
string n,k1,k;
long long ans,p,z;

main()
{cin>>n>>k1; p=cv(n);
z=1;long long y=0;
for (long long i=0; i<k1.size(); i++)
k=k1[i]+k;
string q=""; q+=k[0];
for (long long i=1; i<k.size(); i++)
{
long long u=0; string d=q;while(k[i+u]=='0') {u++; d='0'+d; }
if (cv(k[i+u]+d)>=cv(n) || (int)d.size()-7>(int)n.size() )
 {ans+=cv(q)*z; z*=p;
 q="" ; }
q=k[i]+q;
}
cout<<ans+cv(q)*z<<endl;
}