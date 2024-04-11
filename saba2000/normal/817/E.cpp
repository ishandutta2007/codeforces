#include<bits/stdc++.h>
using namespace std;
map<int,int> M[34];
int type,p,l,q,s,An;
void add(int p,int d)
{int x=29;
while(x+1)
{M[x][p]+=d; p/=2; x--;}}
int ans(int p, int l)
{s=0; An=0;
for(int x=0; x<=29; x++)
{int z=29-x,h=(1<<z)&p,w=(1<<z)&l;
if(h && w) An+=M[x][(s|(1<<z))>>z];
if(!h && w){An+=M[x][s>>z]; s=(s|(1<<z));}
if(h && !w) s=(s|(1<<z));}
return An;}
main()
{cin>>q; while(q--)
{cin>>type>>p;
if(type==1)add(p,1);
if(type==2)add(p,-1);
if (type==3){cin>>l; cout<<ans(p,l)<<endl;}
}}