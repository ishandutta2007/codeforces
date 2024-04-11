#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int x[1005],y[1005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
		sort(x+1,x+n+1),sort(y+1,y+n+1);
		if(n%2==1)
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << (x[n/2+1]-x[n/2]+1)*(y[n/2+1]-y[n/2]+1) << "\n";
		}
	}
	return 0;
}