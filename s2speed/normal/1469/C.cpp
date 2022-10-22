#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef double db;
struct piii {
	int first , second , third;
};

const ll MAX_N = 2e5 + 20 , md = 1e9 + 7;
 
ll tav(ll n , ll k){
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

int a[MAX_N];
pii l[MAX_N] , r[MAX_N];

void solve(){
	int n , k;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		l[i] = {a[i] , a[i] + k - 1};
		r[i] = {l[i].first + k , l[i].second + k};
	}
	l[0] = {a[0] , a[0]};
	r[0].second = r[0].first;
	for(int i = 1 ; i < n ; i++){
		if(l[i].first >= r[i - 1].second || l[i - 1].first >= r[i].second){
			cout<<"NO\n";
			return;
		}
		r[i].first = max(r[i].first , l[i - 1].first + 1);
		l[i].second = min(l[i].second , r[i - 1].second - 1);
		r[i].second = l[i].second + k;
		l[i].first = r[i].first - k;
	}
	if(l[n - 1].first != a[n - 1]){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}