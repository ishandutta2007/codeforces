#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 108 , md = 1e9 + 7;

ll n , m , k , x;
ll has[MAX_N][MAX_N] , res[MAX_N][MAX_N] , a[MAX_N][MAX_N] , cnt[10];

void mul(ll a[MAX_N][MAX_N] , ll b[MAX_N][MAX_N]){
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
			has[i][j] = 0;
		}
	}
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
			for(int k = 0 ; k < x ; k++){
				has[i][j] += 1ll * a[i][k] * b[k][j];
				has[i][j] %= md;
			}
		}
	}
}

void tav(ll b){
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
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
	cin>>n>>m>>k>>x;
	for(int i = 0 ; i < 10 ; i++){
		cnt[i] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		ll inp;
		cin>>inp;
		cnt[inp]++;
	}
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
			a[i][j] = 0;
		}
	}
	for(int i = 0 ; i < x ; i++){
		for(int j = 0 ; j < x ; j++){
			for(int k = 1 ; k < 10 ; k++){
				if((10 * j + k) % x == i){
					a[i][j] += cnt[k];
				}
			}
		}
	}
	tav(m);
	cout<<res[k][0]<<"\n";
	return 0;
}