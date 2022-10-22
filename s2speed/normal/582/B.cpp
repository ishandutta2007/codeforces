#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<ll , pll> plll;

const ll MAX_N = 108;

ll has[MAX_N][MAX_N] , res[MAX_N][MAX_N] , a[MAX_N][MAX_N] , n , b[2 * MAX_N];
vector<ll> dp;

void mul(ll a[MAX_N][MAX_N] , ll b[MAX_N][MAX_N]){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			has[i][j] = -1;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if(a[i][k] == -1 || b[k][j] == -1){
					continue;
				}
				has[i][j] = max(a[i][k] + b[k][j] , has[i][j]);
			}
		}
	}
}

void tav(ll k){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			res[i][j] = 0 - (i != j);
		}
	}
	while(k > 0){
		if(k & 1){
			mul(a , res);
			memcpy(res , has , sizeof(has));
		}
		mul(a , a);
		memcpy(a , has , sizeof(has));
		k /= 2;
	}
}

ll LIS(ll l , ll r){
	dp.clear();
	dp.assign(r - l + 1 , 500);
	for(int i = l ; i < r ; i++){
		if(b[i] < b[l] || b[i] > b[r - 1]){
			continue;
		}
		*upper_bound(dp.begin() , dp.end() , b[i]) = b[i];
	}
	for(int i = 0 ; i < r - l + 1 ; i++){
		if(dp[i] == 500){
			return i;
		}
	}
	return 0;
}

ll o[MAX_N] , ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	
	ll t;
	cin>>n>>t;
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
	}
	for(int i = n ; i < 2 * n ; i++){
		b[i] = b[i - n];
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			a[i][j] = LIS(i , n + j + 1) - 1;
		}
	}
	tav(t - 1);
	ll h = 0;
	if(t == 1){
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				h = max(h , LIS(i , j + 1));
			}
		}
		cout<<h<<'\n';
		return 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			h = max(h , res[i][j]);
		}
	}
	cout<<++h<<'\n';
	return 0;
}