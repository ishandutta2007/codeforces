#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
using namespace __gnu_pbds;
using namespace std;

int n;

inline int calc(int x)
{
	if(x==0||x==n+1) return INF;
	cout<<"? "<<x<<"\n";
	fflush(stdout);
	int y;cin>>y;
	return y;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		int val1=calc(mid-1),val2=calc(mid),val3=calc(mid+1);
		if(val1>val2&&val3>val2){
			cout<<"! "<<mid<<"\n";
			fflush(stdout);
			break;
		}
		if(val2>val1) r=mid-1;
		else if(val2>val3) l=mid+1;
	}
	return 0;
}