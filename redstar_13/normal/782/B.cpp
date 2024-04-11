#include <bits/stdc++.h>
using namespace std;
#define NN 100010
typedef double DO;
int x[NN],v[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	int mn=1e10,mx=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",x+i),mn=min(x[i],mn),mx=max(x[i],mx);
	for(int i=0;i<n;i++)scanf("%d",v+i);
	DO st=mn,ed=mx,t;
	for(int k=0;k<500;k++){
		DO mid=(st+ed)/2;
		DO mm=0,xx=0;
		for(int i=0;i<n;i++){
			t=(x[i]-mid)/v[i];
			if(t>=0 and t>xx)xx=t;
			if(t<=0 and t<mm)mm=t;
		}
		if(xx>=(-1)*mm)st=mid,t=xx;
		else ed=mid,t=mm;
	}
	printf("%.10lf\n",abs(t));
	return 0;
}