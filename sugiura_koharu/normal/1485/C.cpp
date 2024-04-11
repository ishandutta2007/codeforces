#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		int ans=0;
		for(int i=1;i<=x;i++)
		{
			int l=i+1,r=min((x-i)/i,y);
			if(r<l) break;
			ans+=r-l+1;
//			cout << l << " " << r << " " << r-l+1 << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}