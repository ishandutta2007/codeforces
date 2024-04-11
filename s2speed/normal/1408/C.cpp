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

int a[MAX_N];

void solve(){
	int x = 0 , y;
	double n , l , s1 = 1 , p1 = 0 , s2 = 1 , p2 , q = 0 , h , ax , ay; cin>>n>>l; y = n - 1; p2 = l;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	while(x <= y){
	    ax = a[x]; ay = a[y];
		if((ax - p1) / s1 < (p2 - ay) / s2){
			h = (ax - p1) / s1;
			q += h;
			p1 = ax; x++;
			p2 -= h * s2;
			s1++;
		} else {
			h = (p2 - ay) / s2;
			q+= h;
			p2 = ay; y--;
			p1 += h * s1;
			s2++;
		}
	}
	q += (p2 - p1) / (s1 + s2);
	printf("%.10lf\n" , q);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}