#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[100010],b[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			b[i]=a[n/2+i/2+1];
		}
		else{
			b[i]=a[i/2];
		}
	}
	int cnt=0;
	for(int i=2;i<=n-1;i++) if(b[i-1]>b[i]&&b[i+1]>b[i]) cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<endl;
	return 0;
}