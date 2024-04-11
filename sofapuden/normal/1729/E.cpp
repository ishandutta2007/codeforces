#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	ll ans = 0;
	ll ans2 = -1;
	for(int i = 2; i <= 26; ++i){
		cout << '?' << ' ' << 1 << ' ' << i << endl;
		ll x; cin >> x;
		if(x == -1){
			cout << "! " << i-1 << endl;
			return;
		}
		cout << "? " << i << ' ' << 1 << endl;
		ll y; cin >> y;
		ans = max(ans,x+y);
		if(x != y)ans2 = x+y;
	}
	if(ans2 != -1)ans = ans2;
	cout << "! " << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();

}