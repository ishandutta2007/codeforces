#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=200005;
typedef long long LL;
int n,d,vis[20],fa[40];
vector <int> ans,tmp;

int getfa(int x)
{
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}

void merge(int u,int v)
{
	u=getfa(u),v=getfa(v);
	fa[v]=u;
}

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

bool query(int d)
{
	printf("?");
	vector <int> f;
	rep(i,1,n) if(i&(1<<d)) f.pb(i);
	printf(" %d",(int)f.size());
	for(auto i:f) printf(" %d",i);
	puts("");
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	return s[0]=='Y';
}

bool prt()
{
	int x=0;
	rep(i,0,d) if(vis[i]) x|=1<<i;
	if(x>n || x<1) return 0;
	printf("! %d\n",x);
	fflush(stdout);
	char s[5];
	scanf("%s",s);
	if(s[1]==')') return 1;
	return 0;
} 

int main()
{
	scanf("%d",&n);
	rep(i,0,17) if((1<<i)>n) {d=i-1; break;}
	rep(i,0,d) ans.pb(i),vis[i]=-1;
	rep(i,0,2*d+1) fa[i]=i;
	while(ans.size()>1)
	{
		int x1=query(ans.back());
		int x2=query(ans.back());
		if(x1==x2)
		{
			vis[ans.back()]=x1;
			ans.pop_back();
		}
		else
		{
			int x=ans.back();
			ans.pop_back();
			int y1=query(ans.back());
			int y2=query(ans.back());
			if(y1==y2) vis[ans.back()]=y1,ans.pop_back(),ans.pb(x);
			else
			{
				int x3=query(x);
				if(x3==x1) merge(ans.back()<<1|y1,x<<1|x1),merge(ans.back()<<1|y2,x<<1|x2);
				else vis[x]=x3;
			}
		}
	}
	
	rep(i,0,d) if(vis[i]==-1)
	{
		int x=getfa(i<<1);
		if(vis[x>>1]!=-1) vis[i]=vis[x>>1]^(x&1);
		else tmp.pb(i);
	}
	for(auto v:tmp) if(getfa(v<<1)==getfa(tmp[0]<<1)) vis[v]=0; else vis[v]=1;
	if(prt()) return 0;
	for(auto v:tmp) if(getfa(v<<1)==getfa(tmp[0]<<1)) vis[v]=1; else vis[v]=0;
	prt();
	return 0;
}