#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX_N = 120;

struct op{
	ll a , b , c , d , e , f;
};

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

ll a[MAX_N][MAX_N];

vector<op> ans;

void f(ll i , ll j){
	ll b = a[i][j] , c = a[i + 1][j] , d = a[i][j + 1] , e = a[i + 1][j + 1];
	if(e && b && c && d){
		ans.push_back( {i , j , i + 1 , j , i + 1 , j + 1} );
		b = 1 - b;
		c = 1 - c;
		e = 1 - e;
	}
	if(b && !c && !d && !e){
		ans.push_back( {i , j , i + 1 , j , i , j + 1} );
		b = 1 - b;
		c = 1 - c;
		d = 1 - d;
	}
	if(!b && c && !d && !e){
		ans.push_back( {i + 1 , j , i + 1 , j + 1 , i , j} );
		c = 1 - c;
		b = 1 - b;
		e = 1 - e;
	}
	if(!b && !c && d && !e){
		ans.push_back( {i , j + 1 , i , j , i + 1 , j + 1} );
		d = 1 - d;
		b = 1 - b;
		e = 1 - e;
	}
	if(!b && !c && !d && e){
		ans.push_back( {i + 1 , j , i , j + 1 , i + 1 , j + 1} );
		d = 1 - d;
		c = 1 - c;
		e = 1 - e;
	}
	if(b && c && !d && !e){
		ans.push_back( {i + 1 , j + 1 , i + 1 , j , i , j + 1} );
		e = 1 - e;
		c = 1 - e;
		d = 1 - d;
	}
	if(b && !c && d && !e){
		ans.push_back( {i + 1 , j , i , j + 1 , i + 1 , j + 1} );
		e = 1 - e;
		c = 1 - c;
		d = 1 - d;
	}
	if(b && !c && !d && e){
		ans.push_back( {i + 1 , j , i , j + 1 , i + 1 , j + 1} );
		e = 1 - e;
		c = 1 - c;
		d = 1 - d;
	}
	if(!b && c && d && !e){
		ans.push_back( {i + 1 , j , i + 1 , j + 1 , i , j} );
		c = 1 - c;
		b = 1 - b;
		e = 1 - e;
	}
	if(!b && c && !d && e){
		ans.push_back( {i , j , i + 1 , j , i , j + 1} );
		b = 1 - b;
		c = 1 - c;
		d = 1 - d;
	}
	if(!b && !c && d && e){
		ans.push_back( {i + 1 , j , i + 1 , j + 1 , i , j} );
		c = 1 - c;
		b = 1 - b;
		e = 1 - e;
	}
	if(b && c && d && !e){
		ans.push_back( {i , j , i + 1 , j , i , j + 1} );
		b = 1 - b;
		c = 1 - c;
		d = 1 - d;
	}
	if(b && c && !d && e){
		ans.push_back( {i + 1 , j , i + 1 , j + 1 , i , j} );
		c = 1 - c;
		b = 1 - b;
		e = 1 - e;
	}
	if(b && !c && d && e){
		ans.push_back( {i , j + 1 , i , j , i + 1 , j + 1} );
		d = 1 - d;
		b = 1 - b;
		e = 1 - e;
	}
	if(!b && c && d && e){
		ans.push_back( {i + 1 , j , i , j + 1 , i + 1 , j + 1} );
		e = 1 - e;
		c = 1 - c;
		d = 1 - d;
	}
}

void solve(){
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		string s;
		cin>>s;
		for(int j = 0 ; j < m ; j++){
			a[i][j] = s[j] - '0';
		}
	}
	if(n % 2 == 1){
		ll h = n - 1;
		if(a[h][0] == 1){
			ans.push_back( {h , 0 , h - 1 , 0 , h - 1 , 1} );
			a[h][0] = 1 - a[h][0];
			a[h - 1][0] = 1 - a[h - 1][0];
			a[h - 1][1] = 1 - a[h - 1][1];
		}
		for(int j = 1 ; j < m ; j++){
			if(a[h][j] == 1){
				ans.push_back( {h , j , h - 1 , j , h - 1 , j - 1} );
				a[h][j] = 1 - a[h][j];
				a[h - 1][j] = 1 - a[h - 1][j];
				a[h - 1][j - 1] = 1 - a[h - 1][j - 1];
			}
		}
	}
	if(m % 2 == 1){
		ll h = m - 1;
		if(a[0][h] == 1){
			ans.push_back( {0 , h , 0 , h - 1 , 1 , h - 1} );
			a[0][h] = 1 - a[0][h];
			a[0][h - 1] = 1 - a[0][h - 1];
			a[1][h - 1] = 1 - a[1][h - 1];
		}
		for(int j = 1 ; j < n ; j++){
			if(a[j][h] == 1){
				ans.push_back( {j , h , j , h - 1 , j - 1 , h - 1} );
				a[j][h] = 1 - a[j][h];
				a[j][h - 1] = 1 - a[j][h - 1];
				a[j - 1][h - 1] = 1 - a[j - 1][h - 1];
			}
		}
	}
	for(int i = 0 ; i < n - 1 ; i += 2){
		for(int j = 0 ; j < m - 1 ; j += 2){
			f(i , j);
		}
	}
	cout<<ans.size()<<"\n";
	for(auto o : ans){
		cout<<o.a + 1<<" "<<o.b + 1<<" "<<o.c + 1<<" "<<o.d + 1<<" "<<o.e + 1<<" "<<o.f + 1<<"\n";
	}
	ans.clear();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}