#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cout<<(n-1)/2<<endl;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			cout<<a[n/2+i/2+1]<<" ";
		}
		else{
			cout<<a[i/2]<<" ";
		}
	}
	cout<<endl;
	return 0;
}