#include <iostream>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int l=0,r=100000,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int X=mid*2+1,Y=X*X/2,Z=Y+1;
			if(Z<=n) ans=X,l=mid+1;
			else r=mid-1;
		}
		cout << ans/2 << "\n";
	}
	return 0;
}