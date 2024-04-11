#include<bits/stdc++.h>

using namespace std;
map<string,int> m;
string A[5009];
int a[5009],b[5009];
int p[5009],v[5009];
int main()
{int n,M;
m["?"]=0;
cin>>n>>M;
for (int i=1; i<=n; i++)
{string x;
cin>>x; m[x]=i;
cin>>x>>x; A[i]=x;
if(x[0]=='1' || x[0]=='0') continue;
else {a[i]=m[A[i]];cin>>x; if(x[0]=='X') p[i]=1; else if(x[0]=='A') p[i]=2; else p[i]=3;
cin>>x;
b[i]=m[x];
}
}string d,e;
for (int j=0; j<M; j++)
{int l=0,r=0;
int k[5009],q[5009];
k[0]=0; q[0]=1;
for (int i=1; i<=n; i++)
{if(A[i][0]=='0' || A[i][0]=='1') {k[i]=A[i][j]-'0'; q[i]=A[i][j]-'0'; continue;}
else {if(p[i]==1) k[i]=(k[a[i]]-'0')^(k[b[i]]-'0');
else if(p[i]==2) k[i]=(k[a[i]]-'0')&(k[b[i]]-'0');
else k[i]=(k[a[i]]-'0')|(k[b[i]]-'0');
if(p[i]==1) q[i]=(q[a[i]]-'0')^(q[b[i]]-'0');
else if(p[i]==2) q[i]=(q[a[i]]-'0')&(q[b[i]]-'0');
else q[i]=(q[a[i]]-'0')|(q[b[i]]-'0');
l+=k[i]; r+=q[i];
}
}
if(l<=r)  d+='0';
else d+='1';
if(l>=r) e+='0';
else e+='1';
}
cout<<d<<endl<<e<<endl;;
}