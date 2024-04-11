#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		ll x;
		cin >> n >> x;
		map<ll, int> mp;
		for(int i = 0; i < n; i++){
			ll a;
			cin >> a;
			mp[a]++;
		}
		int ans = 0;
		while(mp.size()){
			P p = *mp.begin();
			if(p.second == 0){
				mp.erase(mp.begin());
				continue;
			}
			int a = p.first;
			if(mp[a * x] >= p.second) mp[a * x] -= p.second;
			else{
				ans += p.second - mp[a * x];
				mp[a * x] = 0;
			}
			mp.erase(mp.begin());
		}
		cout << ans << endl;
	}
}