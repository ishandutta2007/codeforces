#include <bits/stdc++.h>
using namespace std;
const int N=5022;
typedef long long LL;
const int MOD=1e9+7;
int n,m;
LL s[N],f[N],h[N];
LL x[N],y[N],res[N],flag[N];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		//s[i]=rand()%100+1;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&f[i],&h[i]);
		//f[i]=rand()%100+1,h[i]=rand()%100+1;
	}

	for(int i=1;i<=m;i++){
		int r=h[i]; x[i]=n+1;
		for(int j=1;j<=n;j++){
			if(s[j]==f[i]) {
				r--; 
				if(r==0) {
					x[i]=j; break;
				}
			}
		}
		r=h[i]; y[i]=0;
		for(int j=n;j>=1;j--){
			if(s[j]==f[i]){
				r--;
				if(r==0){
					y[i]=j; break;
				}
			}
		}
	}

	for(int i=0;i<=n;i++){
		LL vis[N][3]={0};
		//[1,i] [i+1,n]
		int ans=0; LL tmp=1;
		for(int j=1;j<=m;j++){
			if(x[j]<=i && y[j]<i+1) {
				vis[f[j]][0]++;
			}
			if(x[j]> i && y[j]>=i+1) {
				vis[f[j]][1]++;
			}
			if(x[j]<=i && y[j]>=i+1) {
				vis[f[j]][2]++;
			}
		}

		LL c1=0, c2=0, c3=0;
		for(int j=1;j<=m;j++){
			if(f[j] == s[i]) {
				if(x[j]==i) {
					if(y[j]<i+1) c1++;
					else c2++;
				} else if (y[j]>=i+1) {
					c3++;
				}
			}
		}
		//printf("%d, %d %d\n",i, c1,c2);
		if(i){
			if(c1+c2==0) continue;
			if(c1>0) {
				if(c2>0||c3>0) {
					ans+=2;
					tmp=tmp*((1LL*c1%MOD*(c2+c3)%MOD + 1LL*c2*c3%MOD + 1LL*c2*(c2-1)%MOD)%MOD)%MOD;
				} else {
					ans+=1;
					tmp=tmp*c1%MOD;
				}
			} else{
				if ((c2>0?1:0) + (c3>0?1:0) == 2) ans += 2, tmp = tmp * ((1LL*c2*c3%MOD + 1LL*c2*(c2-1)%MOD)%MOD) % MOD;
				else if(c2>=2) ans+=2, tmp=tmp*(1LL*c2*(c2-1)%MOD)%MOD;
				else ans++, tmp = tmp * c2 % MOD;
			}
		}

		for(int j=1;j<=n;j++){
			if (j == s[i]) continue;
			if( (vis[j][0]>0?1:0) + (vis[j][1]>0?1:0) + (vis[j][2]>0?1:0) >= 2 ) {
				tmp = tmp * ((1LL * vis[j][0] * vis[j][1] + 1LL * vis[j][1] * vis[j][2] + 1LL * vis[j][0] * vis[j][2] + 1LL * vis[j][2] * (vis[j][2] - 1) % MOD) % MOD) % MOD;
				ans += 2;
			} else if (vis[j][2] >= 2) {
				tmp = tmp * (1LL * vis[j][2] * (vis[j][2] - 1) % MOD) % MOD;
				ans += 2;
			} else if( (vis[j][0]>0?1:0) + (vis[j][1]>0?1:0) + (vis[j][2]>0?1:0) == 1 ) {
				ans ++;
				tmp = tmp * (vis[j][0] + vis[j][1] + 2 * vis[j][2]) % MOD;
			}
		}	
		
		//printf("i=%d, tmp= %lld, ans=%d\n", i,tmp, ans);
		if(flag[ans]==0) flag[ans]=1;
		res[ans]=(res[ans]+tmp)%MOD;
	}
	for(int i=N-1;i>=0;i--){
		if(flag[i]){
			return !printf("%d %lld\n", i,res[i]);
		}
	}
}