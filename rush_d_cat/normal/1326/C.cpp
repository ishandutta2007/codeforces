#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
const int MOD=998244353;
int n,k,p[N],a[N];
int main() {
	vector<int> v;
	scanf("%d%d",&n,&k);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]>=n-k+1) {
			v.push_back(i);
			sum+=p[i];
		}
	}
	int ans=1;
	for(int i=1;i<v.size();i++){
		ans=ans*(long long)(v[i]-v[i-1])%MOD;
	}
	printf("%lld %d\n",sum, ans);
}