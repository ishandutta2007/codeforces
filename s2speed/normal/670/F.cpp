#include<bits/stdc++.h>
#include<fstream>
 
using namespace std;

#pragma GCC optimize ("Ofast")

#define all(x) x.begin() , x.end()
//#define mp make_pair
#define gcd __gcd
typedef long long int ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef long double db;
struct plll {ll first , second , third;};
typedef pair<int , pii> piii;
typedef pair<pll , pll> pllll;

const ll MAXN = 5e5 + 20 , md = 1e9 + 7 , inf = 5e18;
// check problem statement

ll dig(ll x){
	ll cnt = 0;
	while(x > 0){
		cnt++;
		x /= 10;
	}
	return cnt;
}

ll cnt[10];

int main(){ // check MAXN
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	memset(cnt , 0 , sizeof(cnt));
	string s , h , ans , sna , b;
	bool g = true;
	cin>>s>>h;
	ll n = s.size() , k = h.size() , q = dig(n) , v , w = -1;
	v = n - q + 1;
	if(dig(v) == q - 1){
		w = v;
	}
	v--;
	if(dig(v) == q){
		w = v;
	}
	for(int i = 0 ; i < n ; i++){
		cnt[s[i] - '0']++;
	}
	if(n == 2 && cnt[0]){
		cout<<"0\n";
		return 0;
	}
	ll y = w;
	while(y > 0){
		cnt[y % 10]--;
		y /= 10;
	}
	for(int i = 0 ; i < k ; i++){
		cnt[h[i] - '0']--;
	}
	for(int i = 1 ; i < k ; i++){
		if(h[i] == h[0]) continue;
		g = (h[i] < h[0]);
		break;
	}
	for(int i = 1 ; i < 10 ; i++){
		if(cnt[i]){
			cnt[i]--;
			ans += '0' + i;
			b += '0' + i;
			break;
		}
	}
	ll o = h[0] - '0';
	for(int i = 0 ; i < 10 ; i++){
		if(i == o && g){
			ans += h;
		}
		char c = i + '0';
		for(int j = 0 ; j < cnt[i] ; j++){
			b += c;
			ans += c;
		}
		if(i == o && !g){
			ans += h;
		}
	}
	sort(all(b));
	sna += h; sna += b;
	if((sna < ans && sna[0] != '0') || (ans[0] == '0')){
		cout<<sna<<'\n';
	} else {
		cout<<ans<<'\n';
	}
	return 0;
}

/*

*/