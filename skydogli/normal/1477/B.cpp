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
int T,n,m;
int a[MN];
char s[MN],f[MN];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
int tag[MN<<2],sum[MN<<2];
void build(int x,int l,int r){
	tag[x]=-1;
	sum[x]=0;
	if(l==r){sum[x]=(f[l]=='1');return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	sum[x]=sum[Ls]+sum[Rs];
}
void pd(int x,int l,int r){
	if(tag[x]!=-1){
		tag[Ls]=tag[Rs]=tag[x];
		sum[Ls]=tag[x]*(mid-l+1);
		sum[Rs]=tag[x]*(r-mid);
		tag[x]=-1;
	}
}
void change(int x,int l,int r,int b,int e,int v){
	if(b<=l&&r<=e){tag[x]=v;sum[x]=v*(r-l+1);return;}
	if(l>e||r<b)return;
	pd(x,l,r);
	change(Ls,l,mid,b,e,v);
	change(Rs,mid+1,r,b,e,v);
	sum[x]=sum[Ls]+sum[Rs];
}
int ask(int x,int l,int r,int b,int e){
	if(b<=l&&r<=e)return sum[x];
	if(l>e||r<b)return 0;
	pd(x,l,r);
	return ask(Ls,l,mid,b,e)+ask(Rs,mid+1,r,b,e);
}
int l[MN],r[MN];
signed main(){
	T=read();
	while(T--){
		n=read();int q=read();
		scanf("%s%s",s+1,f+1);
		for(int i=1;i<=q;++i){
			l[i]=read(),r[i]=read();
		}
		build(1,1,n);
		bool ok=1;
		for(int i=q;i;--i){
			int v=ask(1,1,n,l[i],r[i]);
			if(v*2<(r[i]-l[i]+1)){
				change(1,1,n,l[i],r[i],0);
			}
			else if((r[i]-l[i]+1-v)*2<r[i]-l[i]+1)
				change(1,1,n,l[i],r[i],1);
			else{
				ok=0;
			}
		}
		for(int i=1;i<=n;++i){
//			cerr<<i<<": "<<ask(1,1,n,i,i)<<endl;
			if((s[i]=='0')^(ask(1,1,n,i,i)==0))ok=0;
		}
		if(ok)puts("YES");
		else puts("NO");
	}
	return 0;
}