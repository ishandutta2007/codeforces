#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 1e5;

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

ll a[MAX_N] , u[MAX_N];
stack<ll> st , bt;
vector< pair<ll , ll> > ans;

void solve(){
	bool start = false , p = true , e = true;
	ll n , l3 = -1;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		if(a[i] == 0){
			
		} else if(a[i] == 1){
			start = true;
			st.push(0);
		} else if(a[i] == 2){
			if(!start){
				p = false;
			}
			if(st.size() == 0){
				p = false;
			} else {
				st.pop();
			}
		} else {
			if(!start){
				p = false;
			}
		}
	}
	if(!p){
		cout<<"-1\n";
		return;
	}
	for(int i = 0 ; i < n ; i++){
		if(a[i] == 2){
			e = true;
		} else if(a[i] == 3) {
			e = false;
			l3 = i;
		}
	}
	if(e == false){
		for(int i = n - 1 ; i >= 0 ; i--){
			if(a[i] == 1){
				if(e == false){
					e = true;
				} else {
					bt.push(0);
				}
			}
			if(a[i] == 2){
				if(bt.size() == 0){
					p = false;
				} else {
					bt.pop();
				}
			}
		}
	}
	if(!p){
		cout<<"-1\n";
		return;
	}
	ll x = 0 , y = n , v , o = 1;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == 1){
			u[i] = y;
			ans.push_back( {y , i + 1} );
			y--;
		}
	}
	v = y;
	y = 0;
	while(y < n){
		while(a[x] != 2 && x < n){
			x++;
		}
		y = max(y , x);
		while(a[y] != 1 && y < n){
			y++;
		}
		if(x >= n || y >= n){
			break;
		}
		ans.push_back( {u[y] , x + 1} );
		x++;
		y++;
	}
	x = 0;
	y = 0;
	while(x < n && o <= v){
		while(a[x] != 3 && x < n){
			x++;
		}
		y = max(y , x + 1);
		if(x == l3){
			while(a[y] != 2 && y < n){
				y++;
			}
			if(y == n){
				y = n - 1;
				while(a[y] != 1){
					y--;
				}
			}
		} else {
			while(a[y] != 3 && y < n){
				y++;
			}
		}
		if(x >= n || y >= n){
			break;
		}
		ans.push_back( {o , x + 1} );
		ans.push_back( {o , y + 1} );
		o++;
		x++;
		y++;
	}
	ll as = ans.size();
	cout<<as<<"\n";
	for(int i = 0 ; i < as ; i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	solve();
	return 0;
}