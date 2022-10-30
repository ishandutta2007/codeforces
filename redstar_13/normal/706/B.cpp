#include <bits/stdc++.h>
using namespace std;
#define NN 100010
int a[NN],f[NN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=10000000;
	int con=1;
	int cnt=1;
	long long TT=a[n]+1000;
	for(int i=1;i<=n;i++)
		for(int j=a[i-1];j<a[i];j++)f[j]=i-1;

		
	int q;
	long long m;
	cin>>q;
	while(q--){
		scanf("%lld",&m);
		if(m>=a[n]) cout<<n<<endl;
		else printf("%d\n",f[m]);
	}
	
	
	return 0;
}