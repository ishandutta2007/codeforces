#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define mn 455
int T,n,m,blk;
int loc(int x){return (x-1)/blk+1;}
int a[MN],b[MN],tagk[mn],tagb[mn],id[MN];
int st[mn][mn],top[mn],pos[mn];
bool use[MN];
bool cmp(int x,int y){return a[x]<a[y];}
double getx(int i,int j){
	return 1.0*(b[i]-b[j])/(a[j]-a[i]);
}
void build(int x){
	int l=(x-1)*blk+1,r=min(x*blk,n);
	top[x]=0;pos[x]=1;
	for(int i=l;i<=r;++i){
		if(use[id[i]])continue;
		b[id[i]]+=tagk[x]*a[id[i]]+tagb[x];
		if(top[x]&&a[st[x][top[x]]]==a[id[i]]&&b[st[x][top[x]]]>b[id[i]])continue;
		while(top[x]&&a[st[x][top[x]]]==a[id[i]]&&b[st[x][top[x]]]<=b[id[i]])top[x]--;
		while(top[x]>1&&getx(st[x][top[x]-1],st[x][top[x]])>=getx(st[x][top[x]-1],id[i]))top[x]--;
		st[x][++top[x]]=id[i];
	}
	tagk[x]=tagb[x]=0;
}
int _f(int id,int x){return a[id]*x+b[id];}
pii getmx(int x){
	if(!top[x])return mp(0,0);
	while(pos[x]<top[x]&&_f(st[x][pos[x]],tagk[x])<_f(st[x][pos[x]+1],tagk[x]))pos[x]++;
	return mp(_f(st[x][pos[x]],tagk[x])+tagb[x],st[x][pos[x]]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		b[i]=a[i]=read();	
	}
	blk=sqrt(n);T=(n-1)/blk+1;
	for(int i=1;i<=n;++i)id[i]=i;
	for(int i=1;i<=T;++i){
		int l=(i-1)*blk+1,r=min(i*blk,n);
		sort(id+l,id+r+1,cmp);
		build(i);
	}
	int ans=0;
	while(1){
		pii res=mp(0,0);
		for(int i=1;i<=T;++i){
			pii w=getmx(i);
			if(res<w)res=w;
		}
		if(!res.y)break;
		ans+=res.x;
		use[res.y]=1;
		int x=loc(res.y);
		for(int i=1;i<x;++i)tagb[i]+=a[res.y];
		for(int i=x+1;i<=T;++i)tagk[i]++;
		for(int i=(x-1)*blk+1;i<res.y;++i)
			b[i]+=a[res.y];
		for(int i=res.y+1;i<=x*blk&&i<=n;++i)
			b[i]+=a[i];
		build(x);
	}
	printf("%lld\n",ans);
	return 0;
}