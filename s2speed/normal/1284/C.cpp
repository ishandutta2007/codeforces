#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 250001;

ll fact[MAX_N];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , m , ans = 0;
	cin>>n>>m;
	const ll md = m;
	fact[0] = 1;
	for(int i = 1 ; i <= n ; i++){
		fact[i] = fact[i - 1] * i % md;
	}
	for(int i = 1 ; i <= n ; i++){
		ans += (fact[i] * (n - i + 1) % md) * fact[n - i + 1];
		ans %= md;
	}
	cout<<ans<<"\n";
	return 0;
}