#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back

using namespace std;
const int N=100005;
int t,n,cnt[N],c,x,y;
int p[N],C[N],P[N],a[N];
vector <int> vt[N];

struct data
{
	int id,cnt;
	bool operator < (const data &x) const
	{
		return x.cnt==cnt?id<x.id:x.cnt<cnt;
	}
} ;

set <data> st;

void init()
{
	st.clear();
	rep(i,1,n+1) cnt[i]=0,p[i]=0;
	rep(i,1,n+1) vt[i].clear();
}

void PRT()
{
	rep(i,1,n+1) if((int)vt[i].size()>0) st.insert((data){i,(int)vt[i].size()});
	rep(i,1,x)
	{
		int id=st.begin()->id;
		st.erase(st.begin());
		p[vt[id].back()]=id;
		vt[id].pop_back();
		if((int)vt[id].size()>0) st.insert((data){id,(int)vt[id].size()});
	}

	int nn=n-x,t=0;

	while(!st.empty())
	{
		int id=st.begin()->id;
		st.erase(st.begin());
		int sz=vt[id].size();
		rep(i,1,sz) ++t,C[t]=id,P[t]=vt[id].back(),vt[id].pop_back();
	}
	rep(i,1,nn>>1) p[P[nn-((nn>>1)-i)]]=C[i];
	rep(i,(nn>>1)+1,nn) p[P[i-(nn>>1)]]=C[i];
	int tot=0;
	rep(i,1,nn) if(p[P[i]]==C[i]) ++tot,p[P[i]]=c;
	if(tot>n-y) puts("NO");
	else
	{
		puts("YES");
		tot=n-y-tot;
		rep(i,1,nn)
		{
			if(!tot) break;
			if(p[P[i]]!=c) --tot,p[P[i]]=c;
		}
		rep(i,1,n) printf("%d ",p[i]);
		puts("");
	}
}

void solve()
{
	rep(i,1,n) ++cnt[a[i]],vt[a[i]].pb(i);
	rep(i,1,n+1) if(!cnt[i]) c=i;
	int mx1=0,mx2=0,c1,c2;
	rep(i,1,n+1) 
		if(cnt[i]>=mx1) mx2=mx1,c2=c1,mx1=cnt[i],c1=i;
		else if(cnt[i]>=mx2) mx2=cnt[i],c2=i;

	if(mx2==0)
	{
		if(x==y)
		{
			puts("YES");
			rep(i,1,y) printf("%d ",c1);
			rep(i,y+1,n) printf("%d ",c);
		}
		else puts("NO");
		return;
	}
	
	PRT();
}	

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		rep(i,1,n) scanf("%d",&a[i]);
		init();
		solve();
	}
	return 0;
}