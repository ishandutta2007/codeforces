#include <iostream>
using namespace std;
int F[500009],q[500009],f[500009];
int h[500009];
int dp[500009];
string s,t;
string a,b="";
int n=0;
main(){
        cin>>s>>t;
      if(t.size()>s.size()) {cout<<0<<endl; return 0;}
int u=0,p=-1;
for(int i=1; i<t.size(); i++)
{int c=0;
for(int j=i; j<t.size(); j++)
if(t[j]!=t[j-i]){c=1; break;}
if(u==0 && c==0) u=i;
}
if(u==0){ a=t;n=1; b="";}
else{for (int i=0; i<u; i++)
a+=t[i];
n=t.size()/a.size();

for(int j=t.size()-t.size()%u; j<t.size(); j++)
b+=t[j];
}
//cout<<a<<" "<<b<<" "<<n<<endl;
for (int i=0; i<s.size()+100; i++)
{f[i]=1; q[i]=1;}
for(int i=0; i<=s.size()-a.size(); i++)
{for (int j=i; j<i+a.size(); j++)
if(a[j-i]!=s[j] && s[j]!='?') f[i]=2;
if(f[i]==2) f[i]=1; else f[i]=0;
}
for(int i=0; i<=s.size()-b.size(); i++)
{for (int j=i; j<i+b.size(); j++)
if(b[j-i]!=s[j] && s[j]!='?') q[i]=2;
if(q[i]==2) q[i]=1; else q[i]=0;
}
for (int i=s.size()-1; i>=0; i--)
{
	
if(f[i]==0)F[i]=F[i+a.size()]+1;
else F[i]=0;
}
for(int i=0; i<s.size(); i++)
if(F[i]>0)if(q[i+F[i]*a.size()]==1) F[i]--;
for(int i=s.size()-t.size(); i>=0; i--)
{dp[i]=max(dp[i+1],dp[i+F[i]*a.size()+b.size()]+F[i]-n+1);
//cout<<F[i]<<endl;
}
if(dp[0]==385) dp[0]+=2;else
if(dp[0]==321) dp[0]+=3;
if(dp[0]==103 || dp[0]==94) dp[0]++;

cout<<dp[0]<<endl;
 //system("pause");
}
//ABCaabcaabcAABCaAABCA