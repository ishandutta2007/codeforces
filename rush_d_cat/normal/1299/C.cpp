#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10; 
typedef long long LL;
int n,nex[N];
LL a[N],sum[N];
pair<LL,LL> stk[N]; int top;
bool chk(pair<LL,LL> A,pair<LL,LL> B,pair<LL,LL> C){
	pair<LL,LL> k1=make_pair(B.first-A.first,B.second-A.second);
	pair<LL,LL> k2=make_pair(C.first-B.first,C.second-B.second);
	// k1.second / k1.first >= k2.second / k2.first return true;
	if (k2.first * k1.second >= k1.first * k2.second) return true;
	return false;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		nex[i]=i;
	}
	stk[top=1]=make_pair(n,sum[n]);
	for(int i=n;i>=1;i--){
		while(top>=2) {
			if(chk(make_pair(i-1,sum[i-1]), stk[top], stk[top-1])) -- top;
			else break;
		}
		nex[i] = stk[top].first;
		stk[++top] = make_pair(i-1,sum[i-1]);
	}
	int now=1;
	while(now<=n){
		int l=now,r=nex[now];
		double val = 1.0*(sum[r]-sum[l-1])/(r-l+1);
		for(int i=l;i<=r;i++)printf("%.10f\n", val);
		now=nex[now]+1;
	}
}