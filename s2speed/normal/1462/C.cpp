#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 1e5 + 20 , md = 1e9 + 7;
 
int tav(ll n , ll k){
	ll res = 1;
	while(k > 0){
		if(k & 1){
			res *= n;
		}
		n *= n;
		k /= 2;
	}
	return res;
}

void solve(){
	int n , k;
	string ans;
	cin>>n;
	if(n > 45){
		cout<<"-1\n";
		return;
	}
	for(int i = 9 ; n > 0 ; i--){
		ans += i + '0';
		n -= i;
	}
	k = ans.size();
	ans[k - 1] += n;
	reverse(ans.begin() , ans.end());
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}