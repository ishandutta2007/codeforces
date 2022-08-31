#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
LL f[22][N];
int n,k;
int a[N];

int cnt[N];
LL num;
int L,R;
void add(int x){
	num+=cnt[x];
	cnt[x]++;
}
void del(int x){
	cnt[x]--;
	num-=cnt[x];
}
void gao(int l,int r){
	while(L>l)add(a[--L]);
	while(R<r)add(a[++R]);
	while(L<l)del(a[L++]);
	while(R>r)del(a[R--]);
}
void work(int l,int r,int sl,int sr,LL *f,LL *g){
	if(l>r)return;

	int mid=(l+r)>>1;

	int jc=0;
	rep(i,sl,min(sr,mid)){
		gao(i,mid);
		if(num+g[i-1]<f[mid]){
			f[mid]=g[i-1]+num;
			jc=i;
		}
	}
	if(mid+1<=r){
		gao(jc,mid);
		work(mid+1,r,jc,sr,f,g);
	}
	gao(sl,l);
	if(l<=mid-1){
		work(l,mid-1,sl,jc,f,g);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&a[i]);

	rep(i,0,k)rep(j,0,n)f[i][j]=1ll<<61;
	f[0][0]=0;
	rep(i,1,k){
		memset(cnt,0,sizeof cnt);
		L=1;R=n;
		rep(j,1,n)add(a[j]);
		work(1,n,1,n,f[i],f[i-1]);
	}
	cout<<f[k][n]<<endl;
	return 0;
}