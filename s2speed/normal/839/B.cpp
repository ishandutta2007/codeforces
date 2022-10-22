#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 0;

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

bool solve(){
	ll n , k , s4 , s2 , s1;
	cin>>n>>k; s4 = n; s2 = n * 2; s1 = 0;
	for(int i = 0 ; i < k ; i++){
		ll h;
		cin>>h;
		if(s4 >= h / 4){
			s4 -= h / 4;
			h %= 4;
		} else {
			h -= s4 * 4;
			s4 = 0;
		}
		if(h >= 2){
			if(s2 >= h / 2){
				s2 -= h / 2;
				h %= 2;
			} else {
				h -= s2 * 2;
				s2 = 0;
			}
		}
		if(s4 > 0 && h < 4 && h != 0){
			if(h == 1){
				s4--;
				s2++;
			} else if(h == 3){
				s4--;
			} else {
				s4--;
				s1++;
			}
			h = 0;
		}
		if(s2 > 0 && h != 0){
			s2--;
			h = 0;
		}
		if(s1 >= h){
			s1 -= h;
			h = 0;
		} else {
			h -= s1;
			s1 = 0;
		}
		if(h > 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	if(solve()){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
	return 0;
}