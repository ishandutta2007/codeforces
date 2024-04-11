#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=310000;
int f[2][205];
int n,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)a[i]/=1000;
	memset(f,63,sizeof f);
	int now=0;
	f[now][0]=0;
	int S=200;
	rep(i,1,n){
		memset(f[now^1],63,sizeof f[now^1]);
		rep(j,0,S){
			//yj
			f[now^1][min(j+a[i],S)]=min(f[now^1][min(j+a[i],S)],f[now][j]+a[i]*1000);
			//yh
			if(j>=a[i]*10)
			f[now^1][j-a[i]*10]=min(f[now^1][j-a[i]*10],f[now][j]);
			//lst
			if(1){
				if(j<=a[i]*10)
				f[now^1][0]=min(f[now^1][0],f[now][j]+a[i]*1000-j*100);
			}
		}
		now^=1;
	}
	int ans=1<<30;
	rep(i,0,S)ans=min(ans,f[now][i]);
	printf("%d\n",ans);
	return 0;
}