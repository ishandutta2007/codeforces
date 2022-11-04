#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define NN 303030
#define inf 0x3f3f3f3f

int f[NN], w[NN];
int flag[NN], cnt[NN];
int dp[NN], sum[NN];
vector<int> vec[NN];

int calc(int x) {
	if(dp[x]<inf) return dp[x];
	for(int j: vec[x]) if(j>1 && sum[j]) {
		smin(dp[x], calc(x/j)+1);
	}
	return dp[x];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	for(int i=2; i<NN; i++) dp[i]=inf;
	
	w[1]=f[1]=1;
	for(int i=2; i<NN; i++) {
		if(!f[i]) {
			f[i]=i;
			if((INT)i*i<NN) {
				for(int j=i*i; j<NN; j+=i) if(!f[j]) {
					f[j]=i;
				}
			}
		}
		if(i/f[i]%f[i]==0) w[i]=0;
		else w[i]=w[i/f[i]]*-1;
	}
	for(int i=1; i<NN; i++) if(w[i]) {
		for(int j=i; j<NN; j+=i) if(w[j]) {
			vec[j].pb(i);
		}
	}
	
	int n, g=0; scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x, u=1; scanf("%d", &x);
		g=__gcd(g, x);
		while(x>1) {
			int p=f[x]; u*=p;
			while(x && x%p==0) x/=p;
		}
		flag[u]=1;
	}
	if(g>1) return puts("-1");
	
	for(int i=1; i<NN; i++) if(w[i]) {
		for(int j=i; j<NN; j+=i) cnt[i]+=flag[j];
	}
	for(int i=1; i<NN; i++) if(w[i]) {
		for(int x: vec[i]) sum[i]+=w[x]*cnt[x];
	}
	
	int ans=inf;
	for(int i=1; i<NN; i++) if(flag[i]) {
		smin(ans, calc(i)+1);
		for(int x: vec[i]) if(x>1) dp[x]=inf;
	}
	cout<<ans<<endl;
}