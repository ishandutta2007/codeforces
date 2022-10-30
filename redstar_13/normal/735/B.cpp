#include <bits/stdc++.h>
using namespace std;
#define NN 100100
int a[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n,p,q;
	cin>>n>>p>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long s=0,t=0;double v=0;
	if(p>q){ for(int i=n;i>=n-q+1;i--)s+=a[i];v+=(double)s/q;
			 for(int i=n-q;i>=n-q-p+1;i--)t+=a[i];v+=(double)t/p;
	}
	else {for(int i=n;i>=n-p+1;i--)s+=a[i];v+=(double)s/p;
		  for(int i=n-p;i>=n-q-p+1;i--)t+=a[i];v+=(double)t/q;
	}
	printf("%.8lf",v);
	
	return 0;
}