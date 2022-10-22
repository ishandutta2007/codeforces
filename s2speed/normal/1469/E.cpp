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

const ll MAX_N = 1 << 20 , md = 1 << 20;
 
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

bool ch[MAX_N];
int l , nt[MAX_N];

void solve(){
	int n , k;
	string s;
	cin>>n>>k>>s;
	for(int i = 0 ; i <= n ; i++){
		ch[i] = true;
	}
	for(int i = 0 ; i < n ; i++){
		if(s[i] == '0'){
			s[i] = '1';
		} else {
			s[i] = '0';
		}
	}
	l = 1e8;
	for(int i = n - 1 ; i >= 0 ; i--){
		if(s[i] == '1'){
			l = i;
		}
		nt[i] = l;
	}
	int x = 0 , y = k , h = 0;
	for(int i = 0 ; i < k ; i++){
		h *= 2;
		h += s[i] - '0';
		h %= md;
	}
	if(nt[x] >= y - 19){
		ch[h] = false;
	}
	bool up = (k <= 20);
	while(y < n){
		if(up && s[x] == '1'){
			int q = 1 << (k - 1);
			h -= q;
		}
		x++;
		h *= 2;
		h %= md;
		h += s[y] - '0';
		if(nt[x] >= y - 19){
			ch[h] = false;
		}
		y++;
	}
	int ans;
	for(int i = 0 ; i < MAX_N ; i++){
		if(ch[i]){
			ans = i;
			break;
		}
	}
	h = 1;
	int cnt = 0 , dbch = 0;
	s.clear();
	while(cnt < k){
		s += '0' + bool(ans & h);
		dbch += (ans & h);
		cnt++;
		h *= 2;
	}
	if(!ch[dbch]){
		cout<<"NO\n";
		return;
	}
	reverse(all(s));
	cout<<"YES\n"<<s<<'\n';
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