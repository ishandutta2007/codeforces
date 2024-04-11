#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int to[1000003],nxt[1000003],head[1000003],val[1000003],f[1000003],t[1000003],cnt=0;
int d[1000003];
struct cmp  
{  
    bool operator ()(const pair<int,int> &a, const pair<int,int> &b)  
    {  
        if(1LL*(a.first-(a.first/2))*a.second!=1LL*(b.first-(b.first/2))*b.second) return 1LL*(a.first-(a.first/2))*a.second>1LL*(b.first-(b.first/2))*b.second; 
		return a.first>b.first; 
    }  
};  
void dfs(int x,int fa,int from)
{
	if(d[x]==1 && x!=1) 
	{
		t[from]=1;
		return ;
	}
	for(int i=head[x]; i; i=nxt[i]) if(to[i]!=fa)
	{
		dfs(to[i],x,i);
		t[from]+=t[i];
	}
	return ;
}
multiset<pair<int,int>,cmp> s1,s2;
long long ans1[5000003],ans2[5000003];
int cnt1,cnt2,n,m,ans;
int bs(long long k)
{
	int res=cnt2,l=0,r=cnt2;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ans2[mid]>=k) res=mid,r=mid-1; else l=mid+1;
	}
	return res;
}
int main()
{
	int T=read(); while(T--)
	{
		s1.clear(),s2.clear(),cnt=cnt1=cnt2=0;
		n=read(),ans=1000000007,m=(n-1)<<1;
		for(int i=1; i<=n; i++) head[i]=0,d[i]=0;
		for(int i=1; i<=m; i++) t[i]=0;
		long long S=-readll(); 
		for(int i=1; i<n; i++) 
		{
			int u=read(),v=read(),w=read(),qwq=read();
			to[++cnt]=v,val[cnt]=w,f[cnt]=qwq,nxt[cnt]=head[u],head[u]=cnt;
			to[++cnt]=u,val[cnt]=w,f[cnt]=qwq,nxt[cnt]=head[v],head[v]=cnt;
			d[u]++,d[v]++;
		}
		dfs(1,1,0);
		for(int i=1; i<=m; i++) if(t[i]) {
			S+=1LL*val[i]*t[i];
			if(f[i]==1) s1.insert(make_pair(val[i],t[i]));
			else s2.insert(make_pair(val[i],t[i]));
		}
		long long tS=0;
		while(tS<=S)
		{
			if(s1.empty()) break;
			pair<int,int> tmp=*s1.begin();
			s1.erase(s1.begin());
			tS+=1LL*(tmp.first-(tmp.first/2))*tmp.second;
			tmp.first/=2;
			if(tmp.first) s1.insert(tmp);
			ans1[++cnt1]=tS;
		}
		tS=0;
		while(tS<=S)
		{
			if(s2.empty()) break;
			pair<int,int> tmp=*s2.begin();
			s2.erase(s2.begin());
			tS+=1LL*(tmp.first-(tmp.first/2))*tmp.second;
			tmp.first/=2;
			if(tmp.first) s2.insert(tmp);
			ans2[++cnt2]=tS;
		}
		for(int i=0; i<=cnt1; i++) 
		{
			if(ans1[i]+ans2[cnt2]<S) continue;
			if(ans1[i]>=S) { ans=min(ans,i); break; }
			ans=min(ans,i+2*bs(S-ans1[i]));
		}
		printf("%d\n",ans);
	}
    return 0;
}