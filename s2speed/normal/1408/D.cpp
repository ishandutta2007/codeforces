#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2000 , MAX_Y = 1e6 + 1;

ll e[MAX_Y];
vector< pair<ll , ll> > r , s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for(int i = 0 ; i < MAX_Y ; i++){
		e[i] = 0;
	}
	ll n , m , ans = 1e18;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		ll inp1 , inp2;
		cin>>inp1>>inp2;
		r.push_back( make_pair(inp1 , inp2) );
	}
	for(int i = 0 ; i < m ; i++){
		ll inp1 , inp2;
		cin>>inp1>>inp2;
		s.push_back( make_pair(inp1 , inp2) );
	}
	ll rs = r.size() , ss = s.size();
	for(int i = 0 ; i < rs ; i++){
		for(int j = 0 ; j < ss ; j++){
			ll a = r[i].first , b = r[i].second , c = s[j].first , d = s[j].second;
			if(a > c || b > d){
				continue;
			} else {
				e[d - b] = max(e[d - b] , c - a + 1);
			}
		}
	}
	for(int i = MAX_Y - 2 ; i >= 0 ; i--){
		e[i] = max(e[i] , e[i + 1]);
	}
	for(int i = 0 ; i < MAX_Y ; i++){
		ans = min(ans , e[i] + i);
	}
	cout<<ans<<"\n";
	return 0;
}