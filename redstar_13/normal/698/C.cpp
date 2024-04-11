#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
typedef double DO;
#define NN 22
DO p[NN];
DO dp[1<<NN];
DO ans[1<<NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lf",&p[i]);
	dp[0]=1;
	for(int i=1;i<1<<n;i++){
		if(__builtin_popcount(i)>k) continue;
		DO sum=0;
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0) sum+=p[j];
		}
		for(int j=0;j<n;j++){
			if(p[j]<eps) continue;
			if(i&(1<<j)){
				DO add=dp[i^(1<<j)]*p[j]/(sum+p[j]);
				ans[j]+=add;
				dp[i]+=add;
			}
		}
	}
  	for(int i=0;i<n;i++) printf("%.8lf ",ans[i]);
    return 0;
}