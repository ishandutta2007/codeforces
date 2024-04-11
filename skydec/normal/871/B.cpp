#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=10005;
int n;
int f[N],g[N];
int BB;
int p[N];
int b[N];
int res[N];
int cnt[N];
bool ok(){
	rep(i,0,n-1){
		if(p[i]>=n)return 0;
		if(b[i]>=n)return 0;
	}
	rep(i,0,n-1)cnt[i]=0;
	rep(i,0,n-1)cnt[p[i]]++;
	rep(i,0,n-1)if(cnt[i]!=1)return 0;
	rep(i,0,n-1)cnt[i]=0;
	rep(i,0,n-1)cnt[b[i]]++;
	rep(i,0,n-1)if(cnt[i]!=1)return 0;
	rep(i,0,n-1)if(p[b[i]]!=i)return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		printf("? 0 %d\n",i);
		fflush(stdout);
		scanf("%d",&f[i]);
	}
	rep(i,1,n-1){
		printf("? %d 0\n",i);
		fflush(stdout);
		scanf("%d",&g[i]);
	}
	printf("? 0 0\n");
	fflush(stdout);
	scanf("%d",&BB);
	int ans=0;
	rep(i,0,n-1){
		//p0
		p[0]=i;
		b[0]=BB^i;
		rep(j,1,n-1)b[j]=f[j]^i;
		if(b[0]>=n)continue;
		rep(j,1,n-1)p[j]=g[j]^b[0];

		if(ok()){
			++ans;
			rep(j,0,n-1)res[j]=p[j];
		}
	}
	printf("!\n");
	printf("%d\n",ans);
	rep(i,0,n-1)printf("%d ",res[i]);
	fflush(stdout);
	return 0;
}