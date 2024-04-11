#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast,unroll-loops")

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

int cnt[MAX_N] , a[MAX_N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n , k , m , ans = -1;
	cin>>n>>k>>m;
	fill(cnt , cnt + m , 0);
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		cnt[a[i] % m]++;
	}
	for(int i = 0 ; i < m ; i++){
		if(cnt[i] >= k){
			ans = i;
			break;
		}
	}
	if(ans == -1){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	int cn = 0;
	for(int i = 0 ; i < n && cn < k ; i++){
		if(a[i] % m == ans){
			cout<<a[i]<<' ';
			cn++;
		}
	}
	cout<<'\n';
	return 0;
}