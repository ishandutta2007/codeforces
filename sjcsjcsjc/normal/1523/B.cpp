#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,a[10010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<3*n<<'\n';
		for(int i=1;i<=n;i+=2){
			cout<<"2 "<<i<<" "<<i+1<<'\n';
			cout<<"1 "<<i<<" "<<i+1<<'\n';
			cout<<"1 "<<i<<" "<<i+1<<'\n';
			cout<<"2 "<<i<<" "<<i+1<<'\n';
			cout<<"1 "<<i<<" "<<i+1<<'\n';
			cout<<"1 "<<i<<" "<<i+1<<'\n';
		}
	}
	return 0;
}