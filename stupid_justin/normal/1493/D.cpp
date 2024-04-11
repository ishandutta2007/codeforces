#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
using namespace std;

const int N=2e5+5;
const int mod=1e9+7;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

map<int,int> m[N];
set<pair<int,int> > S[N];
int n,q,cnt,y,x,ans=1;;
int a[N],p[N];
bool vis[N];
bool chk(int x)
{
	for(int i=2;i*i<=x;i++) if (x%i==0) return 0;
	return 1;
}
signed main()
{
	for (int i=2;i<N;i++) if (chk(i)) p[++cnt]=i;
    rd(n);rd(q);
	for (int i=1;i<=n;i++)
	{
    	rd(x);
    	for (int j=1;j<=cnt;j++)
		{
			if (p[j]*p[j]>x) break;      
      		if (!(x%p[j])) {auto it=m[i].insert({p[j],0}).fi;while(!(x%p[j])) x/=p[j],it->se++;}
    	}
    	if (x!=1) m[i][x]=1;
    	for(auto it:m[i]) S[it.fi].insert({it.se,i});
  	}
    for (int i=1;i<=cnt;i++) if (n==S[p[i]].size()) ans=ans*ksm(p[i],S[p[i]].begin()->fi)%mod;
	while (q--)
	{
     	rd(y);rd(x);
    	map<int,int> tmp;
    	for (int j=1;j<=cnt;j++) 
		{
			if (p[j]*p[j]>x) break;      
      		if (!(x%p[j])) {auto it=tmp.insert({p[j],0}).fi;while(!(x%p[j])) x/=p[j],it->se++;}
    	}
    	if (x!=1) tmp[x]=1;
    	for(auto it:tmp) 
		{
      		auto rr=m[y].find(it.fi);
      		int bur=0,cur=0;
      		if (rr==m[y].end()) cur=it.se,bur=0,rr=m[y].insert(it).fi;
        	else bur=rr->se,cur=bur+it.se,rr->se+=it.se;
       		if (n==S[it.fi].size()) ans=ans*ksm(ksm(it.fi,S[it.fi].begin()->fi))%mod;
      		S[it.fi].erase({bur,y});
      		S[it.fi].insert({cur,y});
      		if (n==S[it.fi].size()) ans=ans*ksm(it.fi,S[it.fi].begin()->fi)%mod;
    	}
    	cout<<ans<<'\n';
  	}
}