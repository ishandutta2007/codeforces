#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N=2001000;
const int M=N<<1;
int mx[M],fa[M],c[M][2],rt[M],la,tot;
int hd[M],nt[M];
inline void apd(int w,int id){
	int p=la,nw=la=++tot;
	mx[nw]=mx[p]+1,rt[nw]=id;
	for(;p&&!c[p][w];p=fa[p])c[p][w]=nw;
	if(!p)fa[nw]=1;
	else{
		int q=c[p][w];
		if(mx[q]==mx[p]+1)fa[nw]=q;
		else{
			int x=++tot;
			mx[x]=mx[p]+1;
			rt[x]=rt[q];
			c[x][0]=c[q][0];
			c[x][1]=c[q][1];
			fa[x]=fa[q];
			fa[nw]=fa[q]=x;
			for(;p&&c[p][w]==q;p=fa[p])c[p][w]=x;
		}
	}
}
int rk[N],idx;
char s[N];
char res[N];
int p[N];
int n,can[N];

void dfs0(int x){
	if(rt[x]&&rt[x]<=n)rk[rt[x]]=++idx;
	if(hd[x]){
		if(!nt[hd[x]])dfs0(hd[x]);
		else{
			int a=hd[x],b=nt[a];
			if(s[rt[a]+mx[x]]>s[rt[b]+mx[x]])std::swap(a,b);
			dfs0(a);
			dfs0(b);
		}
	}
}

int m0[N],m1[N];
int main() {
	// freopen("1.in", "r", stdin);
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin>>s+1,n=strlen(s+1),la=tot=1;
	rep(i,1,n)p[i]=p[i-1]+(s[i]=='('?1:-1);
	int c0=0,c1=0;m1[n+1]=1e9;
	rep(i,1,n)c0+=s[i]=='(',c1+=s[i]==')';
	rep(i,1,n)m0[i]=std::min(m0[i-1],p[i]);
	for(int i=n;i>=1;--i)m1[i]=std::min(m1[i+1],p[i]);

	int ad=0;
	if(c0<c1)ad=c1-c0;
	rep(i,1,n)
	if(std::min(m1[i]-p[i-1],m0[i-1]+(p[n]-p[i-1]))+ad>=0)can[i]=1;

	memcpy(s+n+1,s+1,n);
	for(int i=n+n;i>=1;--i)apd(s[i]==')',i);
	rep(i,2,tot) nt[i]=hd[fa[i]],hd[fa[i]]=i;
	dfs0(1);
	int u=-1;
	rep(i,1,n)if(can[i])if(u==-1||rk[u]>rk[i])u=i;
	if(c0>=c1){
		rep(i,u,u+n-1)cout.put(s[i]);
		rep(i,c1+1,c0)cout.put(')');
	} else{
		rep(i,c0+1,c1)cout.put('(');
		rep(i,u,u+n-1)cout.put(s[i]);
	}
}