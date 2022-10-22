#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
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
LL res,f[2][MN];
int a[MN],n,k,vis[MN],L,R,id;
void calc(int l,int r){
	while(L<l){vis[a[L]]--;res-=vis[a[L]];L++;}
	while(L>l){L--;res+=vis[a[L]];vis[a[L]]++;}
	while(R>r){vis[a[R]]--;res-=vis[a[R]];R--;}
	while(R<r){R++;res+=vis[a[R]];vis[a[R]]++;}
}
void work(int l,int r,int L,int R){
	if(l>r)return;
	int mid=(l+r)>>1,rr=min(mid-1,R),lead=L;
	for(int i=L;i<=rr;++i){
		calc(i+1,mid);
		if(f[id][mid]>f[!id][i]+res)
			f[id][mid]=f[!id][i]+res,lead=i;
	}
//	cerr<<"calc: "<<id<<" "<<mid<<": "<<f[id][mid]<<endl;
	work(l,mid-1,L,lead);
	work(mid+1,r,lead,R);
}
int main(){
	n=read();k=read();
	L=1;R=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		calc(1,i);
		f[1][i]=res;
		f[0][i]=1e18;
	}
	id=1;
	for(int i=2;i<=k;++i){
		id^=1;
		work(1,n,0,n-1);
		for(int j=1;j<=n;++j)f[id^1][j]=1e18;
	}
	printf("%lld\n",f[id][n]);
	return 0;
}