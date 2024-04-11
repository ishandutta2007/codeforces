#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=100005;
int n,k,Q;
int ty[N],qx[N],qy[N];
int a[15][N];
bitset<4096> ww[N];
int m;
int main(){
	scanf("%d%d%d",&n,&k,&Q);
	rep(i,1,k)rep(j,1,n)scanf("%d",&a[i][j]);
	rep(i,1,Q){
		scanf("%d%d%d",&ty[i],&qx[i],&qy[i]);
	}

	rep(i,0,(1<<k)-1){
		rep(j,1,k)ww[j][i]=((i&(1<<(j-1)))>0);
	}
	m=k;
	rep(i,1,Q){
		if(ty[i]==1){
			ww[++m]=(ww[qx[i]]|ww[qy[i]]);
		}
		if(ty[i]==2){
			ww[++m]=(ww[qx[i]]&ww[qy[i]]);
		}
		if(ty[i]==3){
			int ans=0;
			rep(j,1,k){
				int ss=0;
				rep(l,1,k)if(a[l][qy[i]]>=a[j][qy[i]])ss|=(1<<(l-1));
				if(ww[qx[i]][ss])ans=max(ans,a[j][qy[i]]);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}