//In the name of God
#include <bits/stdc++.h>
using namespace std;
int arr[16];
int main(){
	int n,l,r,x;
	cin >> n >> l >> r >> x;
	for(int i = 0; i < n;i++) cin >> arr[i];
	int ans = 0;
	for(int i = 0; i < (1 << n);i++){
		int mn = 1e9,mx = 0;
		int sum = 0;
		for(int j = 0; j < n;j++) if(i >> j & 1) sum += arr[j],mn = min(mn,arr[j]),mx = max(mx,arr[j]);
		if(l <= sum && sum <= r && mx - mn >= x) ans++;
	}
	cout << ans << endl;
	return 0;
}