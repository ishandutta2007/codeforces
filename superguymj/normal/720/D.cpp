#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)
#define pb push_back

using namespace std;
const int N=1000005,mod=1000000007;
int n,m,k,ans;
struct data
{
	int x,y;
	
	bool operator < (const data &t) const
	{
		return x==t.x?y<t.y:x<t.x;
	}
};
vector <data> vt[N],es[N];
set <data> st;

struct seg
{
	bool cur[N<<2];
	int t[N<<2],ql,qr,x;

	void modify(int L,int R,int tmp)
	{
		if(L==R) ins(1,m,1,L,tmp);
		else ql=L,qr=R,x=tmp,cv(1,m,1);
	}

	void ins(int l,int r,int rt,int x,int y)
	{
		if(l==r) {t[rt]=y; return;}
		pd(rt);
		if(x<=mid) ins(l,mid,lch,x,y);
		else ins(mid+1,r,rch,x,y);
		pu(rt);
	}

	void pu(int rt)
	{
		t[rt]=(t[lch]+t[rch])%mod;
	}

	void T(int rt)
	{
		cur[rt]=1,t[rt]=0;
	}

	void pd(int rt)
	{
		if(cur[rt]) T(lch),T(rch),cur[rt]=0;
	}

	void cv(int l,int r,int rt)
	{
		if(ql<=l && r<=qr) {T(rt); return;}
		pd(rt);
		if(ql<=mid) cv(l,mid,lch);
		if(mid<qr) cv(mid+1,r,rch);
		pu(rt);
	}

	int query(int L,int R)
	{
		return ql=L,qr=R,query(1,m,1);
	}
	
	int query(int l,int r,int rt)
	{
		if(ql>qr) return 0;
		if(ql<=l && r<=qr) return t[rt];
		pd(rt);
		if(qr<=mid) return query(l,mid,lch);
		if(mid<ql) return query(mid+1,r,rch);
		return (query(l,mid,lch)+query(mid+1,r,rch))%mod;
	}
} t;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

bool cmp(data a,data b)
{
	return a.x==b.x?a.y>b.y:a.x>b.x;
}

int main()
{
	n=getint(),m=getint(),k=getint();
	rep(i,1,k)
	{
		int a=getint(),c=getint(),b=getint(),d=getint();
		vt[a].pb((data){c,d});
		es[b+1].pb((data){c,d});
	}
	t.modify(1,1,1);
	rep(i,1,n) sort(vt[i].begin(),vt[i].end(),cmp);
	int sz=vt[1].size();
	rep(i,0,sz-1) 
		st.insert(vt[1][i]);
	st.insert((data){0,0});
	rep(i,2,n)
	{
		sz=vt[i].size();
		rep(j,0,sz-1)
			if(vt[i][j].y<m)
			{
				data p=*(--st.lower_bound((data){vt[i][j].y+2,0}));
				int nw=t.query(p.y+1,vt[i][j].y+1);
				t.modify(vt[i][j].y+1,vt[i][j].y+1,nw);
			}
		sz=es[i].size();
		rep(j,0,sz-1) st.erase(es[i][j]);
		sz=vt[i].size();
		rep(j,0,sz-1) st.insert(vt[i][j]),t.modify(vt[i][j].x,vt[i][j].y,0);
	}
	data p=*(--st.end());
	ans=t.query(p.y+1,m);
	printf("%d\n",ans);
	return 0;
}