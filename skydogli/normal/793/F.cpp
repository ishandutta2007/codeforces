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
#define MN 100005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int n,m,q,X[MN],Y[MN],ans[MN];
pii a[MN];
vector<int>chg[MN],Q[MN];
int mx[MN<<2],sec[MN<<2],tag[MN<<2];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
void pd(int x){
	if(tag[x]){
		if(mx[Ls]==mx[Rs])tag[Ls]=tag[Rs]=mx[Ls]=mx[Rs]=tag[x];
		else if(mx[Ls]>mx[Rs])tag[Ls]=mx[Ls]=tag[x];
		else tag[Rs]=mx[Rs]=tag[x];
		tag[x]=0;
	}
}
void pushup(int x){
	mx[x]=max(mx[Ls],mx[Rs]);
	if(mx[Ls]==mx[Rs])sec[x]=max(sec[Ls],sec[Rs]);
	else if(mx[Ls]<mx[Rs])sec[x]=max(mx[Ls],sec[Rs]);
	else sec[x]=max(sec[Ls],mx[Rs]);
}
void build(int x,int l,int r){
	if(l==r){mx[x]=l;return;}
	build(Ls,l,mid);
	build(Rs,mid+1,r);
	pushup(x);
}
void change(int x,int l,int r,int b,int e,int X,int Y){
//	cerr<<"fk "<<l<<" "<<r<<" "<<b<<" "<<e<<" "<<X<<": "<<mx[x]<<endl;
	if(l>e||r<b||mx[x]<X)return;	
	if(b<=l&&r<=e){
//		cerr<<"chg "<<l<<" "<<r<<": "<<mx[x]<<" "<<sec[x]<<" "<<X<<" "<<Y<<endl;
		if(l==r){if(mx[x]>=X)mx[x]=Y;return;}
		if(sec[x]<X){mx[x]=Y;tag[x]=Y;return;}
	}
	pd(x);	
	if(b<=mid)change(Ls,l,mid,b,e,X,Y);
	if(e>mid) change(Rs,mid+1,r,b,e,X,Y);
	pushup(x);
//	cerr<<"OK "<<l<<" "<<r<<": "<<mx[x]<<" "<<mx[Ls]<<" "<<mx[Rs]<<endl;
}
int ask(int x,int l,int r,int loc){
	if(l==r)return mx[x];
	pd(x);
	if(loc<=mid)return ask(Ls,l,mid,loc);
	else return ask(Rs,mid+1,r,loc);
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		a[i].x=read(),a[i].y=read();
		chg[a[i].y].pb(a[i].x);
	}
	q=read();
	for(int i=1;i<=q;++i){
		X[i]=read(),Y[i]=read();
		Q[Y[i]].pb(i);
	}
	build(1,1,n);
	for(int i=1;i<=n;++i){
		for(int j=0;j<chg[i].size();++j){
//			cerr<<"chg: "<<chg[i][j]<<" "<<i<<endl;
			change(1,1,n,1,chg[i][j],chg[i][j],i);
		}
		for(int j=0;j<Q[i].size();++j){
//			cerr<<"qry "<<X[Q[i][j]]<<" "<<i<<" "<<": "<<ask(1,1,n,X[Q[i][j]])<<endl;
			ans[Q[i][j]]=ask(1,1,n,X[Q[i][j]]);
		}
	}
	for(int i=1;i<=q;++i)printf("%lld\n",ans[i]);
	return 0;
}