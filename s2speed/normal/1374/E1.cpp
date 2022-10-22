#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

vector<ll> a , b , c;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll n , k , h , aa , bb , as , bs , cs , ans = 0;
	cin>>n>>k;
	for(int i = 0 ; i < n ; i++){
		cin>>h>>aa>>bb;
		if(aa == 1 && bb == 1){
			c.push_back(h);
		} else if(aa == 1){
			a.push_back(h);
		} else if(bb == 1){
			b.push_back(h);
		}
	}
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	as = a.size();
	bs = b.size();
	cs = c.size();
	if(as + cs < k || bs + cs < k){
		cout<<-1<<"\n";
		return 0;
	}
	as = min(as , bs);
	for(int i = 0 ; i < as ; i++){
		c.push_back(a[i] + b[i]);
	}
	sort(c.begin() , c.end());
	for(int i = 0 ; i < k ; i++){
		ans += c[i];
	}
	cout<<ans<<endl;
	return 0;
}