//In the name of God
#include <bits/stdc++.h>
//I Looked at peyman jabbarzadeh's code
using namespace std;
typedef long long ll;
ll ans = 9e18;
const ll Maxn = 1e5 + 9;
ll sum[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n = 0;
	cin >> n;
	for(int i = 0; i < n;i++){
		ll p;
		cin >> p;
		sum[i+1] = sum[i] + p;
	}
	for(ll i = 1; i <= n;i++){
		for(ll j = max((ll)1,i - 2000); j < i;j++) ans = min(ans,(sum[i] - sum[j]) * (sum[i] - sum[j]) + (i - j) * (i - j));
	}
	cout << ans << endl;
}