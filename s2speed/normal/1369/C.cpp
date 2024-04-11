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

const ll z = 0;

vector<ll> a , w;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n , h , k , sum = 0 , l = 0 , m;
		cin>>n>>k;
		m = n - 1;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			a.push_back(h);
		}
		for(int i = 0 ; i < k ; i++){
			cin>>h;
			w.push_back(h);
		}
		h = k;
		sort(a.begin() , a.end());
		sort(w.begin() , w.end());
		for(int i = 0 ; i < k ; i++){
			if(w[i] == 1){
				sum += a[m] * 2;
				m--;
			} else {
				h = i;
				break;
			}
		}
		for(int i = k - 1 ; i >= h ; i--){
			sum += a[m] + a[l];
			m--;
			l += w[i] - 1;
		}
		cout<<sum<<"\n";
		a.clear();
		w.clear();
	}
	return 0;
}