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
 
vector<ll> v[20] , g;
set<ll> s[20];
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		g.clear();
		for(int i = 0 ; i < 20 ; i++){
			v[i].clear();
			s[i].clear();
		}
		string a , b;
		ll n , m[20] , ans = 0 , hb , ha , k = -1 , vis;
		for(int i = 0 ; i < 20 ; i++){
			m[i] = 100;
		}
		cin>>n>>a>>b;
		for(int i = 0 ; i < n ; i++){
			if(a[i] > b[i]){
				cout<<-1<<"\n";
				n = -1;
				break;
			} else if(a[i] != b[i]){
				ha = a[i] - 'a';
				hb = b[i] - 'a';
				if(s[ha].count(i) == 0){
					s[ha].insert(i);
					v[ha].push_back(i);
				}
				m[ha] = min(hb , m[ha]);
			} else {
				g.push_back(i);
			}
		}
		if(n == -1){
			continue;
		}
		while(g.size() < n){
			for(int i = k + 1 ; i < 20 ; i++){
				vis = v[i].size();
				if(vis > 0){
					k = i;
					for(int j = 0 ; j < vis ; j++){
						hb = b[v[i][j]] - 'a';
						if(m[i] == hb){
//							cout<<v[i][j]<<endl;
							g.push_back(v[i][j]);
						} else {
							v[m[i]].push_back(v[i][j]);
							m[m[i]] = min(m[m[i]] , hb);
						}
					}
					v[i].clear();
					break;
				}
			}
			ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}