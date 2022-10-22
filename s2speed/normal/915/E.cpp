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

set<pll> s;
vector< set<pll>::iterator > v;
vector<pll> e;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n , q , cnt;
	cin>>n>>q; cnt = n;
	while(q--){
		int l , r , t;
		cin>>l>>r>>t;
		if(t == 2){
			set<pll>::iterator it = s.lower_bound({l , r}) , et = s.end() , bt = s.begin();
			if(it != bt) it--;
			while(it != et){
				pll p = *it;
				int lx = p.second , rx = p.first;
				if(rx < l){
					it++;
					continue;
				}
				if(lx > r) break;
//				cout<<lx<<' '<<rx<<'\n';
				if(lx >= l && r >= rx){
					cnt += rx - lx + 1;
					v.push_back(it);
					it++;
					continue;
				}
				if(lx <= l && rx <= r){
					v.push_back(it);
					e.push_back({l - 1 , lx});
					cnt += rx - l + 1;
					it++;
					continue;
				}
				if(lx >= l && rx >= r){
					v.push_back(it);
					e.push_back({rx , r + 1});
					cnt += r - lx + 1;
					it++;
					continue;
				}
				v.push_back(it);
				e.push_back({l - 1 , lx});
				e.push_back({rx , r + 1});
				cnt += r - l + 1;
				it++;
			}
			for(auto i : v){
				s.erase(i);
			}
			for(auto i : e){
				s.insert(i);
			}
			v.clear();
			e.clear();
		} else {
			set<pll>::iterator it = s.lower_bound({l , r}) , et = s.end() , bt = s.begin();
			if(it != bt) it--;
			while(it != et){
				pll p = *it;
				int lx = p.second , rx = p.first;
				if(rx < l){
					it++;
					continue;
				}
				if(lx > r) break;
				v.push_back(it);
				l = min(l , lx);
				r = max(r , rx);
				cnt += rx - lx + 1;
				it++;
			}
			for(auto i : v){
				s.erase(i);
			}
			v.clear();
			s.insert({r , l});
			cnt -= r - l + 1;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}

/*
500000 4
196303 288435 1
181743 468082 1
454772 467304 2
14914 392969 1
*/