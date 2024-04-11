#include<bits/stdc++.h>

typedef long long ll;
 
using namespace std;

const ll MAX_N = 2e5 + 1;

bool ch[MAX_N];
ll ans[MAX_N];
vector<ll> a , b;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , counter = 0;
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		ch[i] = true;
	}
	for(int i = 1 ; i <= n ; i++){
		ll inp;
		cin>>inp;
		if(inp == 0){
			a.push_back(i);
		} else {
			ch[inp] = false;
			ans[i] = inp;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		if(ch[i] == true){
			b.push_back(i);
		}
	}
	ll as = a.size();
	for(int i = 0 ; i < as ; i++){
		if(a[i] == b[i]) counter++;
	}
	if(counter == 1){
		for(int i = 0 ; i < as ; i++){
			if(a[i] == b[i]){
				if(i > 0){
					swap(b[i] , b[i - 1]);
				} else {
					swap(b[0] , b[1]);
				}
			}
		}
	} else if(counter % 2 == 0){
		ll x = -1;
		for(int i = 0 ; i < as ; i++){
			if(a[i] == b[i]){
				if(x == -1){
					x = i;
				} else {
					swap(b[x] , b[i]);
					x = -1;
				}
			}
		}
	} else {
		ll x = -1 , y = 1e10;
		for(int i = 0 ; i < as ; i++){
			if(a[i] == b[i]){
				if(y == 1e10){
					y = i;
				} else if(x == -1){
					x = i;
				} else {
					if(y != -2){
						swap(b[x] , b[y]);
						swap(b[i] , b[y]);
						y = -2;
						x = -1;
					} else {
						swap(b[x] , b[i]);
						x = -1;
					}
				}
			}
		}
	}
	for(int i = 0 ; i < as ; i++){
		ans[a[i]] = b[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	return 0;
}