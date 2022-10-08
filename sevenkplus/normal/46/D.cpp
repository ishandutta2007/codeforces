
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)
#define tr(e,x) for(typeof(x.begin()) e=x.begin();e!=x.end();e++)
using namespace std;
const int Max_L=100000+100,inf=~0U>>2;
typedef pair<int,int> PI;
PI Ret[1000];
int main()
{
int L,b,f;
cin>>L>>f>>b;
int n;cin>>n;
set<PI> S;S.insert(PI(-inf,-inf));S.insert(PI(inf,inf));
rep(i,n)
{
int t,len;
cin>>t>>len;
if(t==1)
{
bool ok=false;
tr(it,S)
{
if(it==--S.end())continue;
int l=max(it->second+f,0);
++it;
int r=min(it->first-b,L);
--it;
if(r-l>=len)
{
ok=true;
cout<<l<<endl;
Ret[i]=PI(l,l+len);
S.insert(Ret[i]);
break;
}
}
if(!ok)cout<<-1<<endl;
}
else
{
len--;
S.erase(Ret[len]);
}
}
}