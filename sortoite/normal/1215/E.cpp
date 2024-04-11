#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using LL = long long;

template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

const int NN = 4e5+1, MM = 1<<20, TT = 1<<10;
int a[NN];
LL dis[44][44];
LL sum[20][TT];
LL sum1[20][TT];
LL dp[MM][20];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
	
  int n, i, j, k, r, t;
  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", a+i), a[i]--;
  
  for(i=0; i<20; i++) {
  	for(j=0; j<20; j++) if(i!= j) {
  		for(r=0, t=0; r<n; r++) {
  			if(a[r] == i) t++;
  			else if(a[r] == j) dis[i][j]+=t;
  		}
  	}
  }
  
  for(i=0; i<20; i++) {
  	for(j=1; j<TT; j++) {
//  		if(j&(1<<i)) continue;
  		for(r=0; r<10; r++) if(j&(1<<r)) {
  			sum[i][j]=sum[i][j^(1<<r)]+dis[i][r];
  			sum1[i][j]=sum1[i][j^(1<<r)]+dis[i][r+10];
  			break;
  		}
  	}
  }
  
  int mask=(1<<10)-1;
  
  memset(dp, 0x3f, sizeof dp);
  for(i=0; i<20; i++) dp[1<<i][i]=0;
  for(i=1; i<MM; i++) {
  	if(__builtin_popcount(i)<2) continue;
  	for(j=0; j<20; j++) if(i&(1<<j)) {
  		for(k=0; k<20; k++) if(k!=j && (i&(1<<k))) {
  			t=i^(1<<j);
	  		smin(dp[i][j], dp[t][k]+sum[j][t&mask]+sum1[j][t>>10]);
	  	}
	  }
  }
  
  LL ans=0x3f3f3f3f3f3f3f3fll;
  
  for(i=0; i<20; i++) smin(ans, dp[MM-1][i]);
  cout<<ans<<endl;
  
  return 0;
}