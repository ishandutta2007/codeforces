#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define ep emplace_back
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m,q;
int tot;
char str[100010],s[400010];
vector<PII>vec[100010];
int pw[100010];
const int d=31,mod=998244353;
int v1[800010],v2[800010];
int sa[400010],rk[400010],height[400010];
int f[400010][19];
int c[400010];
int logt[400010];
int hsh[400010];
void SA(){
	for(int i=1;i<=tot;++i) v1[i]=s[i]-'a'+1,++c[v1[i]];
	for(int i=2;i<=27;++i) c[i]+=c[i-1];
	for(int i=1;i<=tot;++i) sa[c[v1[i]]--]=i;
		// for(int i=1;i<=tot;++i) printf("%d " ,sa[i]);printf("\n");
	// printf("tot:%d\n",tot);printf("%s\n",s+1);
	for(int k=1;k<tot;k<<=1){
		// printf("k:%d\n",k);
		int cnt=0;memset(c,0,sizeof(c));
		for(int i=tot-k+1;i<=tot;++i) v2[++cnt]=i;
		for(int i=1;i<=tot;++i) if(sa[i]>k) v2[++cnt]=sa[i]-k;
		for(int i=1;i<=tot;++i) c[v1[i]]++;
		for(int i=1;i<=tot;++i) c[i]+=c[i-1];
		for(int i=tot;i>=1;--i){
			sa[c[v1[v2[i]]]--]=v2[i];v2[i]=0;
		}swap(v1,v2);
		cnt=1;v1[sa[1]]=1;
		for(int i=2;i<=tot;++i){
			if(v2[sa[i]]==v2[sa[i-1]]&&v2[sa[i]+k]==v2[sa[i-1]+k]) v1[sa[i]]=cnt;else v1[sa[i]]=++cnt;
		}
		// for(int i=1;i<=tot;++i) printf("%d ",v1[i]);printf("\n");
	}
		// for(int i=1;i<=tot;++i) printf("%d " ,sa[i]);printf("\n");
	for(int i=1;i<=tot;++i) rk[sa[i]]=i;
	for(int i=1,j=0;i<=tot;++i){
		if(j) --j;
		while(s[i+j]==s[sa[rk[i]-1]+j]) ++j;
		height[rk[i]]=j;
	}
	// printf("dffdsa\n");
	for(int i=1;i<=tot;++i){
		f[i][0]=height[i];
	}
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=tot;++i){
			// printf("i:%d,j:%d\n",i,j);
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(int i=2;i<=tot;++i) logt[i]=logt[i>>1]+1;
}
int lcp(int x,int y){
	int l=rk[x],r=rk[y];
	if(l==r) return tot-x+1;
	if(l>r) swap(l,r);++l;
	int k=logt[r-l+1];
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
struct query{
	int l,r,id;
};
vector<query>qr[400010];
int fa[100010],son[100010],dfn[100010],top[100010],idx,rdfn[100010];
int siz[100010],dep[100010];
char vl[100010];
void dfs1(int x,int f){
	siz[x]=1;dep[x]=dep[f]+1;
	fa[x]=f;
	for(PII i:vec[x]){
		if(i.fi==f) continue ;
		vl[i.fi]=i.se;
		dfs1(i.fi,x);
		siz[x]+=siz[i.fi];
		if(siz[i.fi]>siz[son[x]]) son[x]=i.fi;
	}
}
int seq[100010];
void dfs2(int x,int tf){
	dfn[x]=++idx;s[++tot]=vl[x];seq[idx]=x;top[x]=tf;
	if(son[x]){
		dfs2(son[x],tf);
	}
	else return ;
	for(PII i:vec[x]){
		if(i.fi==fa[x]||i.fi==son[x]) continue ;
		dfs2(i.fi,i.fi);
	}
}
struct e{
	int l,r,len;
}up[310],dw[310];
int cu,cd;
int id[400010];
int finds(){
	int l=1,r=tot,res=0;
	auto check=[&](int x){
		// printf("x:%d\n",x);
		int sum=0;
		for(int i=1;i<=cu;++i){
			int l=lcp(x,up[i].l);
			if(l<up[i].len){
				return s[x+l]<s[up[i].l+l];
			}
			else x+=up[i].len;
		}
		// printf("x:%d\n",x);
		return false ;
	};
	while(l<=r){
		int mid=l+r>>1;
		if(check(sa[mid])) res=mid,l=mid+1;else r=mid-1;
	}
	return res;
}
int findb(){
	int l=1,r=tot,res=tot+1;
	auto check=[&](int x){
		// printf("x:%d\n",x);
		for(int i=1;i<=cu;++i){
			int l=lcp(x,up[i].l);
			if(l<up[i].len) return s[x+l]>s[up[i].l+l];
			else x+=up[i].len;
		}
		return false ;
	};
	while(l<=r){
		int mid=l+r>>1;
		if(check(sa[mid])) res=mid,r=mid-1;else l=mid+1;
	}
	return res;
}
int tre[400010];
void upd(int x,int k){
	while(x<=m){
		tre[x]+=k;x+=x&-x;
	}
}
int qry(int x){
	int res=0;
	while(x){
		res+=tre[x];x-=x&-x;
	}
	return res;
}
int ans[100010];
int main(){
	n=read(),m=read(),q=read();pw[0]=1;for(int i=1;i<=n;++i) pw[i]=1ll*pw[i-1]*d%mod;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		char c=getchar();while(c<'a'||c>'z') c=getchar();
		vec[u].ep(v,c);
		vec[v].ep(u,c);
	}vl[1]='a';
	dfs1(1,0);dfs2(1,0);
	for(int i=n;i>=1;--i){
		rdfn[seq[i]]=++tot;s[tot]=vl[seq[i]];
	}
	for(int i=1;i<=m;++i){
		scanf("%s",str+1);s[++tot]='z'+1;
		int l=strlen(str+1);
		for(int j=1;j<=l;++j) s[++tot]=str[j],id[tot]=i;
	}
	SA();
	for(int i=1;i<=q;++i){cu=cd=0;
		int u=read(),v=read(),l=read(),r=read();
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]){
				dw[++cd]=e{dfn[top[v]],dfn[v]};
				v=fa[top[v]];
			}
			else{
				up[++cu]=e{rdfn[u],rdfn[top[u]]};u=fa[top[u]];
			}
		}
		if(dep[u]>dep[v]) up[++cu]=e{rdfn[u],rdfn[v]-1};
		else if(dep[u]<dep[v]) dw[++cd]=e{dfn[u]+1,dfn[v]};
		for(int i=cd;i>=1;--i) up[++cu]=dw[i];
		for(int i=1;i<=cu;++i) up[i].len=up[i].r-up[i].l+1;
		// for(int i=1;i<=cu;++i) printf("%d %d\n",up[i].l,up[i].r);
		int L=finds()+1,R=findb()-1;
		// printf("L:%d,R:%d\n",L,R);
		if(L<=R){
			// printf("L:%d,R:%d\n",L,R);
			qr[L-1].pb(query{l,r,-i});
			qr[R].pb(query{l,r,i});
		}
	}
	for(int i=1;i<=tot;++i){
		if(id[sa[i]]) upd(id[sa[i]],1);
		// printf("i:%d,%d,%d\n",i,sa[i],id[sa[i]]);
		for(query j:qr[i]){
			int res=qry(j.r)-qry(j.l-1);
			if(j.id<0) ans[-j.id]-=res;else ans[j.id]+=res;
		}
	}
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
}