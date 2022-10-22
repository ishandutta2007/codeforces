#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
#define gcd __gcd 
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
typedef pair<ll , pll> plll;
typedef pair<int , pii> piii;

const ll MAXN = 2e5 + 20 , md = 1e9 + 7;
// check problem statement

ll c[MAXN] , b[MAXN] , a[MAXN] , cnt[30];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(cnt , 0 , sizeof(cnt));
	ll n , sum = 0;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>b[i];
		sum += b[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin>>c[i];
		sum += c[i];
	}
	if(sum % (2 * n)){
		cout<<"-1\n";
		return 0;
	}
	sum /= 2 * n;
	for(int i = 0 ; i < n ; i++){
		ll h = b[i] + c[i] - sum;
		if(h < 0 && h % n){
			cout<<"-1\n";
			return 0;
		}
		a[i] = h / n;
	}
	for(int i = 0 ; i < n ; i++){
		ll o = 1;
		for(int j = 0 ; j < 30 ; j++){
			if(a[i] & o){
				cnt[j]++;
			}
			o *= 2;
		}
	}
	for(int i = 0 ; i < n ; i++){
		ll h = 0 , o = 1;
		for(int j = 0 ; j < 30 ; j++){
			if(a[i] & o){
				h += 1ll * o * cnt[j];
			}
			o *= 2;
		}
		if(h != b[i]){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	return 0;
}

/*
4 4
1 2 3
2 3 10
3 4 5
4 1 1
1
1 4
*/