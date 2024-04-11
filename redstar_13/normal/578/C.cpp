#include <bits/stdc++.h>

using namespace std;
typedef double DO;
#define NN 200010
int a[NN];
int n;
DO calc(DO x){
	DO ans=0,sum=0,mn=0,mx=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]-x;
		mx=max(mx,sum);
		mn=min(mn,sum);
		ans=max(ans,fabs(sum-mn));
		ans=max(ans,fabs(sum-mx));
	}
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	DO st=-11111,ed=11111;
	DO midL,midR;
	int step=100;
	while(step--){
		midL=(2*st+ed)/3;
		midR=(st+2*ed)/3;
		if(calc(midL)>calc(midR)) st=midL;
		else ed=midR;
	}
	printf("%.8lf\n",calc(st));
    return 0;
}