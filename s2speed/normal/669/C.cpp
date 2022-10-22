#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
 
const ll MAX_N = 100 + 20 , md = 1e9 + 7;
 
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

int ans[MAX_N][MAX_N];
pii a[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n , m , q;
	cin>>n>>m>>q;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			ans[i][j] = 0;
			a[i][j] = {i , j};
		}
	}
	while(q--){
		int op;
		cin>>op;
		if(op == 3){
			int i , j , k;
			cin>>i>>j>>k; i--; j--;
			ans[a[i][j].first][a[i][j].second] = k;
		} else if(op == 1){
			int i;
			cin>>i; i--;
			for(int j = 1 ; j < m ; j++){
				swap(a[i][j] , a[i][j - 1]);
			}
		} else {
			int j;
			cin>>j; j--;
			for(int i = 1 ; i < n ; i++){
				swap(a[i][j] , a[i - 1][j]);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}