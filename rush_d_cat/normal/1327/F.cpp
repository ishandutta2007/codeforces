#include <bits/stdc++.h>
using namespace std;
const int N=500000+10;
typedef long long LL;
const LL MOD = 998244353;
int n,k,m;
int l[N],r[N],x[N];
int sum[N],idx[N],pre[N],nex[N];
int lef[N],rig[N]; 

int mx1[N]={0},mx2[N]={0};
LL dp[N]={0},presum[N]={0};
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
LL solve(int n,int m,int l[],int r[]){
	if(m==0) return mpow(2,n);
	for(int i=0;i<N;i++){
		mx1[i]=mx2[i]=dp[i]=presum[i]=0;
	}
	/*
	printf("n=%d, m=%d\n", n,m);
	for(int i=1;i<=m;i++){
		printf("%d %d\n", l[i],r[i]);
	}
	*/
	for(int i=1;i<=m;i++){
		mx1[r[i]]=max(l[i],mx1[r[i]]);
		mx2[l[i]]=max(l[i],mx2[l[i]]);
	}
	for(int i=1;i<=n;i++){
		mx1[i]=max(mx1[i],mx1[i-1]);
		mx2[i]=max(mx2[i],mx2[i-1]);
		//printf("%d / %d %d\n", i,mx1[i],mx2[i]);
	}
	dp[0]=1;presum[0]=1;
	for(int i=1;i<=n;i++){
		//dp[i]+=presum[i-1]-((mx2[i]>=1)?presum[mx2[i]-1]:0); 
		//printf("not take [%d, %d]\n", mx2[i], i-1);
		dp[i]+=presum[i-1]-((mx1[i-1]>=1)?presum[mx1[i-1]-1]:0); 
		dp[i]=(dp[i]%MOD+MOD)%MOD;
		(presum[i]=presum[i-1]+dp[i])%=MOD;
		//printf("dp[%d]=%lld\n", i,dp[i]);
	}
	LL res=0;
	//printf("# %d\n", mx2[n]);
	for(int i=n;i>=mx2[n];i--) res=(res+dp[i])%MOD;
	if(m==0) (res+=dp[0])%=MOD;
	//printf("res=%lld\n", res);
	return res;
}

int main() {
	scanf("%d%d%d",&n,&k,&m);
	LL ans=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&l[i],&r[i],&x[i]);
	}
	for(int i=0;i<k;i++){
		//printf("i=%d\n",i);
		for(int j=1;j<=n;j++)sum[j]=0,idx[j]=0,pre[j]=0,nex[j]=0;
		for(int j=1;j<=m;j++){
			if(x[j]>>i&1){
				sum[l[j]]++, sum[r[j]+1]--;
			}
		}
		for(int j=1;j<=n;j++) sum[j]+=sum[j-1];
		int tot=0;
		for(int j=1;j<=n;j++){
			if(sum[j]==0){
				idx[j]=++tot;
			}
		}
		for(int j=1;j<=n;j++){
			pre[j]=pre[j-1];
			if(idx[j])pre[j]=idx[j];
		}
		for(int j=n;j>=1;j--){
			nex[j]=nex[j+1];
			if(idx[j])nex[j]=idx[j];
		}

		int cnt=0;
		for(int j=1;j<=m;j++){
			if(!(x[j]>>i&1)){
				int lb=nex[l[j]];
				int rb=pre[r[j]];
				if(lb==0||rb==0)return !printf("0\n");
				lef[++cnt]=lb, rig[cnt]=rb;
			}
		}
		ans=ans*solve(tot,cnt,lef,rig)%MOD;
	}
	cout<<ans<<endl;
}