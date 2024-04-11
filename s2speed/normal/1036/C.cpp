#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll dp[18][4] , f[18][4];

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	if(k < 0){
		return 0;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll dgcount(ll n){
	ll counter = 0;
	while(n > 0){
		counter++;
		n /= 10;
	}
	return counter;
}

ll count(ll n){
	ll c = 3 , g = dgcount(n) , r = tav(10 , g - 1) , counter = 0;
	while(r > 0){
		ll h = n / r;
		n %= r;
		r /= 10;
		g -= 1;
		if(c == 0){
			break;
		}
		if(h == 0){
			continue;
		}
		for(int i = 0 ; i <= c ; i++){
			counter += f[g][i];
		}
		for(int i = 0 ; i < c ; i++){
			counter += f[g][i] * (h - 1);
		}
		if(g > 0){
			counter += h;
		}
		c--;
	}
	return counter;
}

int main(){
	ios_base::sync_with_stdio(false); cout.tie(NULL); cout.tie(NULL);
	
	ll ans = 0;
	for(int i = 0 ; i < 18 ; i++){
		dp[i][0] = 1;
		dp[i][1] = 9;
		dp[i][2] = 0;
		dp[i][3] = 0;
	}
	dp[0][1] = 0;
	f[0][0] = 1;
	f[0][1] = 0;
	f[0][2] = 0;
	f[0][3] = 0;
	for(int i = 1 ; i < 18 ; i++){
		for(int j = 0 ; j < i ; j++){
			dp[i][2] += dp[j][1] * 9;
			dp[i][3] += dp[j][2] * 9;
		}
		f[i][0] = 0;
		f[i][1] = f[i - 1][1] + dp[i][1];
		f[i][2] = f[i - 1][2] + dp[i][2];
		f[i][3] = f[i - 1][3] + dp[i][3];
	}
//	cout<<f[3][0]<<" "<<f[3][1]<<" "<<f[3][2]<<" "<<f[3][3]<<"\n";
	ll q;
	cin>>q;
	while(q--){
		ans = 0;
		ll l , r;
		cin>>l>>r;
		l--;
		if(r == 1e18){
			ans++;
			r--;
		}
		ans += count(r);
		ans -= count(l);
		cout<<ans<<"\n";
	}
	return 0;
}