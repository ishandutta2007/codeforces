#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[100005];
		for(int i = 0; i < n; i++) cin >> a[i];
		ll ans = 0;
		bool f = false;
		for(int i = 1; i < n - 1; i++){
			if(a[i] > 1) f = true;
			ans += (a[i] + 1) / 2;
		}
		if(n == 3 && a[1] % 2) f = false;
		if(f) cout << ans << endl;
		else cout << -1 << endl;
	}
}