#include<bits/stdc++.h>
using namespace std;
#define MN 300005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
int T,n,m;
char ch[MN];
int a[MN],b[MN];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
int Min[MN<<2],tag[MN<<2],loc[MN],p[MN];
void pd(int x){
	if(tag[x]){
		Min[Ls]+=tag[x];
		Min[Rs]+=tag[x];
		tag[Ls]+=tag[x];
		tag[Rs]+=tag[x];
		tag[x]=0;
	}
}
void cover(int x,int l,int r,int b,int e,int op){
	if(l>e||r<b)return;
	if(b<=l&&r<=e){Min[x]+=op;tag[x]+=op;return;}
	pd(x);
	if(b<=mid)cover(Ls,l,mid,b,e,op);
	if(e>mid)cover(Rs,mid+1,r,b,e,op);
	Min[x]=max(Min[Ls],Min[Rs]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		loc[a[i]]=i;
	}
	int mx=n;
	printf("%d ",mx);
	cover(1,1,n,1,loc[mx],1);
	for(int i=1;i<n;++i){
		int p=read();
		cover(1,1,n,1,p,-1);
		while(Min[1]<=0&&mx){
			mx--;
			cover(1,1,n,1,loc[mx],1);
		}
		printf("%d ",mx);
	}
	return 0;
}