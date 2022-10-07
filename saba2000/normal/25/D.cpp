#include<iostream>
#include<vector>
using namespace std;
int n;
int s[2000],p[2000];
vector<int> m,k;
int fp(int x)
{if(x==p[x])return x;
return p[x]=fp(p[x]);}
void u(int a, int b)
{int x=fp(a),y=fp(b);
if(x==y) return;
if(s[x]>s[y]){p[y]=x; s[y]+=s[x];}
else  {p[x]=y; s[x]+=s[y];}} 
main()
{cin>>n;
for(int i=1; i<=n; i++)
p[i]=i;
for(int  i=1; i<n; i++)
{int a,b;
cin>>a>>b;
if(fp(a)==fp(b)) {m.push_back(a); k.push_back(b);}
u(a,b);
}cout<<m.size()<<endl;
int z=0;
for(int i=1; i<=n; i++)
for(int j=1; j<=n; j++)
if(fp(i)!=fp(j)){cout<<m[z]<<" "<<k[z]<<" "<<i<<" "<<j<<endl; z++;u(i,j);}
}