#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int dp1[2010][2010],sum11[2010][2010],sum12[2010][2010];
int dp2[2010][2010],sum21[2010][2010],sum22[2010][2010];
int pre1[2010],pre2[2010],nxt1[2010],nxt2[2010];
char a[2010],b[2010];

inline void add1(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD; 
}

inline void add2(int &x,int y)
{
	x+=y;
	if(x<0) x+=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=1;i<=n;i+=2){
			if(a[i]=='0') a[i]='1';
			else if(a[i]=='1') a[i]='0';
		}
		for(int i=1;i<=n;i+=2){
			if(b[i]=='0') b[i]='1';
			else if(b[i]=='1') b[i]='0';
		}
		pre1[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]=='1') pre1[i]=i;
			else pre1[i]=pre1[i-1];
		}
		pre2[1]=1;
		for(int i=2;i<=n;i++){
			if(b[i]=='1') pre2[i]=i;
			else pre2[i]=pre2[i-1];
		}
		nxt1[n]=n;
		for(int i=n-1;i>=1;i--){
			if(a[i]=='1') nxt1[i]=i;
			else nxt1[i]=nxt1[i+1];
		}
		nxt2[n]=n;
		for(int i=n-1;i>=1;i--){
			if(b[i]=='1') nxt2[i]=i;
			else nxt2[i]=nxt2[i+1];
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp1[i][j]=0;
				if(i==0&&j==0) dp1[i][j]=1;
				else if(i==0){
					if(b[j]!='1') dp1[i][j]=dp1[i][j-1];
				}
				else if(j==0){
					if(a[i]!='1') dp1[i][j]=dp1[i-1][j]; 
				}
				else{
					if(a[i]!='0'&&b[j]!='0') add1(dp1[i][j],dp1[i-1][j-1]);
					if(a[i]!='1'&&b[j]!='1') add1(dp1[i][j],dp1[i-1][j-1]);
					if(j>=2&&a[i]!='0'&&b[j]!='1'){
						add1(dp1[i][j],sum11[i-1][j-2]);
						if(pre2[j-1]>=2) add2(dp1[i][j],-sum11[i-1][pre2[j-1]-2]);
					}
					if(i>=2&&a[i]!='1'&&b[j]!='0'){
						add1(dp1[i][j],sum12[i-2][j-1]);
						if(pre1[i-1]>=2) add2(dp1[i][j],-sum12[pre1[i-1]-2][j-1]);
					}
				}
				sum11[i][j]=0;
				if(j<=n-1&&b[j+1]!='0') add1(sum11[i][j],dp1[i][j]);
				if(j>=1) add1(sum11[i][j],sum11[i][j-1]);
				sum12[i][j]=0;
				if(i<=n-1&&a[i+1]!='0') add1(sum12[i][j],dp1[i][j]);
				if(i>=1) add1(sum12[i][j],sum12[i-1][j]);
			}
		}
		for(int i=n+1;i>=1;i--){
			for(int j=n+1;j>=1;j--){
				dp2[i][j]=0;
				if(i==n+1&&j==n+1) dp2[i][j]=1;
				else if(i==n+1){
					if(b[j]!='1') dp2[i][j]=dp2[i][j+1];
				}
				else if(j==n+1){
					if(a[i]!='1') dp2[i][j]=dp2[i+1][j];
				}
				else{
					if(a[i]!='0'&&b[j]!='0') add1(dp2[i][j],dp2[i+1][j+1]);
					if(a[i]!='1'&&b[j]!='1') add1(dp2[i][j],dp2[i+1][j+1]);
					if(j<=n-1&&a[i]!='0'&&b[j]!='1'){
						add1(dp2[i][j],sum21[i+1][j+2]);
						if(nxt2[j+1]<=n-1) add2(dp2[i][j],-sum21[i+1][nxt2[j+1]+2]);
					}
					if(i<=n-1&&a[i]!='1'&&b[j]!='0'){
						add1(dp2[i][j],sum22[i+2][j+1]);
						if(nxt1[i+1]<=n-1) add2(dp2[i][j],-sum22[nxt1[i+1]+2][j+1]);
					}
				}
				sum21[i][j]=0;
				if(j>=2&&b[j-1]!='0') add1(sum21[i][j],dp2[i][j]);
				if(j<=n) add1(sum21[i][j],sum21[i][j+1]);
				sum22[i][j]=0;
				if(i>=2&&a[i-1]!='0') add1(sum22[i][j],dp2[i][j]);
				if(i<=n) add1(sum22[i][j],sum22[i+1][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(a[i]!='0'){
			for(int j=1;j<=n;j++) if(b[j]!='0'){
				int val=abs(i-j);
				add1(ans,1ll*val*dp1[i-1][j-1]%MOD*dp2[i+1][j+1]%MOD);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}