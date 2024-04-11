#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 108 , md = 1e9 + 7;

ll n , m;
ll has[MAX_N][MAX_N] , res[MAX_N][MAX_N] , a[MAX_N][MAX_N];

void mul(ll a[MAX_N][MAX_N] , ll b[MAX_N][MAX_N]){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			has[i][j] = 0;
		}
	}
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			for(int k = 0 ; k < m ; k++){
				has[i][j] += 1ll * a[i][k] * b[k][j];
				has[i][j] %= md;
			}
		}
	}
}

void tav(ll b){
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			res[i][j] = (i == j);
		}
	}
	while(b > 0){
		if(b & 1){
			mul(a , res);
			memcpy(res , has , sizeof(res));
		}
		mul(a , a);
		memcpy(a , has , sizeof(a));
		b /= 2;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll ans = 0;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < m ; j++){
			a[i][j] = (i == j - 1);
		}
	}
	a[m - 1][0] = 1;
	a[m - 1][m - 1] = 1;
	tav(n);
	for(int i = 0 ; i < m ; i++){
		ans += res[0][i];
		ans %= md;
	}
	cout<<ans<<"\n";
	return 0;
}