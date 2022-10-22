#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll tav(ll n , ll k){
	if(k == 0){
		return 1;
	}
	ll x = tav(n , k / 2);
	if(k % 2 == 0){
		return x * x;
	} else {
		return x * x * n;
	}
}

ll a[25][25] , ma[25][25] , n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll k , q , x , y;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		a[i][0] = 0;
	}
	for(int i = 1 ; i < n ; i++){
		a[n - 1][i] = 0;
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		for(int j = 1 ; j < n ; j++){
			k = 1;
			for(int q = j - 1 ; q < n ; q++){
				k += a[q][i + 1];
			}
			for(int q = i + 2 ; q < n ; q++){
				k += a[n - 1][q];
			}
			for(int q = i + 1 ; q < n ; q++){
				k -= a[j][q];
			}
			for(int q = j + 1 ; q < n ; q++){
				k -= a[q][n - 1];
			}
			a[j][i] = k;
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	ma[n - 1][n - 1] = 0;
	for(int i = n - 2 ; i >= 0 ; i--){
		ma[n - 1][i] = ma[n - 1][i + 1] + a[n - 1][i];
	}
	for(int i = n - 2 ; i >= 0 ; i--){
		for(int j = 0 ; j < n ; j++){
			ma[i][j] = ma[i + 1][j] + a[i][j];
		}
	}
	cout.flush();
	cin>>q;
	while(q--){
		cout.flush();
		x = 1; y = 1;
		ll h , sum = 0;
		cin>>h;
		for(int i = 0 ; i < 2 * n - 2 ; i++){
			cout<<x<<" "<<y<<"\n";
			sum += a[x - 1][y - 1];
			if(y == n){
				x++;
				for( ; x < n ; x++){
					cout<<x<<" "<<y<<"\n";
				}
				break;
			}
			if(x == n){
				y++;
				for( ; y < n ; y++){
					cout<<x<<" "<<y<<"\n";
				}
				break;
			}
			if(h - sum <= ma[x - 1][y]){
				y++;
			} else {
				x++;
			}
		}
		cout<<x<<" "<<y<<"\n";
	}
	return 0;
}