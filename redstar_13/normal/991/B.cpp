#include<bits/stdc++.h>
#define ep 1e-8
#define NN 110

using namespace std;

int n;
int a[NN];
int main () {
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a,a+n);
	double sum=0.0;
	for(int i=0; i<n; i++) sum+=a[i];
	int ans=0;
	for(int i=0; i<n; i++) {
		if (sum/n>4.5-ep) break;
		ans++;
		sum+=5;
		sum-=a[i];
	}
	cout<<ans<<endl;
	return 0;
}