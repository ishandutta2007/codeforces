#include <iostream>
using namespace std;
int a[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int mn=1e9;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			mn=min(mn,a[i]);
		}
		int ans=n;
		for(int i=1;i<=n;i++)
			ans-=a[i]==mn;
		cout << ans << "\n";
	}
	return 0;
}