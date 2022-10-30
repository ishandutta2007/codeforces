#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005];
signed main(int argc, char** argv) {
	int n,q,k;
	cin >> n >> q >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		int ans=k*2-(r-l+1)*2;
		ans-=a[l]-1,ans-=k-a[r];
		cout << ans << "\n";
	}
	return 0;
}