#include <iostream>
#include <algorithm>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b;
		cin >> a >> b;
		int ans=1e9,qwq=0;
		if(b==1) ++b,qwq=1;
		for(int i=0;i<=ans;i++)
		{
			int t=a,cnt=0;
			while(t) t/=b+i,++cnt;
			ans=min(ans,i+cnt);
		}
		cout << ans+qwq << "\n"; 
	}
	return 0;
}