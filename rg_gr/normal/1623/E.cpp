#include<bits/stdc++.h>
#define BetterIO ios::sync_with_stdio(false)
using namespace std;
#define pair qwqqwqw
struct pair{
	int p,v;
};
int l[1000005],r[1000005],dep[1000005],faa[1000005],dfn[1000005],id[1000005],Id[1000005],cc,qwqwq[1000005],dd,vld[1000005],l2[1000005],r2[1000005],idfn[1000005];
void dfs(int u)
{
	if(u==0)return;
	// cout<<faa[u]<<' '<<u<<endl;
	// cout<<u<<endl;
	++cc;dfn[u]=l2[u]=cc;
	idfn[cc]=u;faa[l[u]]=u;faa[r[u]]=u;
	dep[l[u]]=dep[u]+1;dfs(l[u]);
	qwqwq[++dd]=u;
	Id[u]=dd;
	dep[r[u]]=dep[u]+1;dfs(r[u]);
	r2[u]=cc;
}
// char s[1000005];
string s;
struct SegT
{
	int maxn[2000005],tag[2000005],pos[2000005];
	void pushdown(int o)
	{
		int&t=tag[o];
		maxn[o<<1]+=t;
		maxn[o<<1|1]+=t;
		tag[o<<1]+=t;
		tag[o<<1|1]+=t;
		t=0;
	}
	void build(int o,int l,int r)
	{
		if(l==r)
		{
			pos[o]=l;
			// maxn[o]=(deg[id[l]]==0?dep[id[l]]:-0x3f3f3f3f3f3f3f3fll);
			maxn[o]=dep[idfn[l]];
			// odl(maxn[o]);
			return;
		}
		int m=l+r>>1;
		build(o<<1,l,m);
		build(o<<1|1,m+1,r);
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	void add(int o,int l,int r,int L,int R,int v)
	{
		// for(int i=L;i<=R;i++)minn[i]+=v;
		if(L<=l&&r<=R)
		{
			maxn[o]+=v;
			tag[o]+=v;
			return;
		}
		int m=l+r>>1;
		pushdown(o);
		if(L<=m)add(o<<1,l,m,L,R,v);
		if(m<R)add(o<<1|1,m+1,r,L,R,v);
		maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
	}
	pair que(int o,int l,int r,int L,int R)
	{
		// int res=minn[L];
		// for(int i=L;i<=R;i++)res=min(res,minn[i]);
		// return res;
		if(L<=l&&r<=R)
		{
			return (pair){pos[o],maxn[o]};
		}
		int m=l+r>>1,res=-0x3f3f3f3f3f3f3f3fll-1;
		pair la,ra;la.v=res,ra.v=res;
		pushdown(o);
		// if(L<=m)res=max(res,que(o<<1,l,m,L,R));
		// if(m<R)res=max(res,que(o<<1|1,m+1,r,L,R));
		if(L<=m)la=que(o<<1,l,m,L,R);
		if(m<R)ra=que(o<<1|1,m+1,r,L,R);
		if(la.v>ra.v)return la;
		return ra;
		// maxn[o]=max(maxn[o<<1],maxn[o<<1|1]);
		// pos[o]=(maxn[o]==maxn[o<<1]?pos[o<<1]:pos[o<<1|1]);
		// return res;
	}
}t;
int flg[1000005];
int main(void)
{
    BetterIO;
   	// int Case=1;cin>>Case;while(Case--)
   	{
   		int N,K;
   		cin>>N>>K;
   		cin>>s;
   		s=" "+s;
   		for(int i=1;i<=N;i++)cin>>l[i]>>r[i];
   		dep[1]=1;
   		dfs(1);vld[N+1]=0;
   		// for(int i=1;i<=N;i++)cout<<vld[i]<<' ';cout<<endl;
   		for(int i=N;i>=1;i--)if(s[qwqwq[i]]==s[qwqwq[i+1]])vld[i]=vld[i+1];else vld[i]=s[qwqwq[i]]<s[qwqwq[i+1]];
   		// for(int i=1;i<=N;i++)cout<<qwqwq[i]<<' ';cout<<endl;
   		// for(int i=1;i<=N;i++)cout<<s[qwqwq[i]]<<' ';cout<<endl;
   		// for(int i=1;i<=N;i++)cout<<vld[i]<<' ';cout<<endl;
   		// for(int i=1;i<=N;i++)cout<<dep[i]<<' ';cout<<endl;
   		t.build(1,1,N);
   		// #define qwqwq Id
   		for(int i=1;i<=N;i++)
   		{
   			if(flg[qwqwq[i]])continue;
   			// if(s[qwqwq[i]]<s[qwqwq[i+1]])
   			if(vld[i])
   			{
   				// if(t.)
   				// cout<<"???";
   					int s=t.que(1,1,N,dfn[qwqwq[i]],dfn[qwqwq[i]]).v;
   				// cout<<K<<' '<<i<<' '<<s<<' '<<qwqwq[i]<<endl;
   				if(s<=K)
   				{
   					// cout<<-s<<' '<<qwqwq[i]<<endl;
   					K-=s;
   					// cout<<s<<endl;
   					int u=idfn[t.que(1,1,N,dfn[qwqwq[i]],dfn[qwqwq[i]]).p];
   					// cout<<'?'<<u<<' '<<s<<endl;
   					while(s--)
   					{
   						t.add(1,1,N,l2[u],r2[u],-1);
   						// cout<<u<<endl;
   						flg[u]=1;
   						u=faa[u];
   					}
   				}
   			}
   			else
   			{
   					int s=t.que(1,1,N,dfn[qwqwq[i]],dfn[qwqwq[i]]).v;
   					// cout<<-s<<endl;
   				// if(s<=K)
   				{
   					// K-=s=t.que(1,1,N,dfn[qwqwq[i]],dfn[qwqwq[i]]).v;
   					// cout<<s<<endl;
   					int u=idfn[t.que(1,1,N,dfn[qwqwq[i]],dfn[qwqwq[i]]).p];
   					// cout<<'?'<<u<<' '<<s<<endl;
   					if(s>1000000)continue;
   					s=1;
   					// cout<<"banned "<<u<<' '<<i<<endl;
   					while(s--)
   					{
   						t.add(1,1,N,l2[u],r2[u],100000000);
   						// cout<<u<<endl;
   						// flg[u]=1;
   						u=faa[u];
   					}
   				}
   			}
   			
   		}
   		#undef qwqwq
   		for(int i=1;i<=N;i++)
   		{
   			putchar(s[qwqwq[i]]);
   			if(flg[qwqwq[i]])putchar(s[qwqwq[i]]);
   		}
   	}
    return 0;
}