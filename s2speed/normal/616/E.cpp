#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const ll md = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , m , ans = 0 , s , l;
	cin>>n>>m; s = sqrt(n);
	if(m > n){
		ans = n;
		ans %= md;
		l = m - n;
		l %= md;
		ans *= l;
		ans %= md;
		m = n;
	}
	l = min(s , m);
	for(int i = 2 ; i <= l ; i++){
		ans += n % i;
		ans %= md;
	}
	ll x = s + 1 , y , a0 , h , q , w , e;
	for(int i = s ; i >= 1 && x <= m ; i--){
		y = n / i;
		y = min(m , y);
//		cout<<x<<" "<<y<<"\n";
		a0 = n % y;
		h = a0;
		h %= md;
		q = (y - x + 1);
		e = q;
		e %= md;
		h *= e;
		h %= md;
		w = (y - x);
		if(w % 2 == 0){
			w /= 2;
		} else {
			q /= 2;
		}
		w %= md;
		q %= md;
		q *= w;
		q %= md;
		q *= i;
		q %= md;
		ans += q + h;
		ans %= md;
		x = y + 1;
	}
	cout<<ans<<"\n";
	return 0;
}