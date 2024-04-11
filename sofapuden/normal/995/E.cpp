#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll M;

ll pw(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)ret=ret*a%M;
		a=a*a%M;
		b>>=1;
	}
	return ret;
}

int main(){
	ll u, v; cin >> u >> v >> M;
	map<ll,pair<ll,ll>> Pa;
	for(int i = 0; i <= 30000; ++i){
		ll x = u;
		ll p = x;
		for(int j = 0; j < 100; ++j){
			int z = rand()%3;
			p = x;
			if(z == 0){
				x++;
			}
			if(z == 1){
				x+=M-1;
			}
			if(z == 2){
				x = pw(x,M-2);
			}
			x%=M;
			if(Pa.count(x))continue;
			Pa[x] = {p,z+1};
		}
	}
	while(1){
		ll x = v;
		vector<ll> op;
		for(int i = 0; i < 100; ++i){
			int z = rand()%3;
			if(z == 0){
				x+=M-1;
			}
			if(z == 1){
				x++;
			}
			if(z == 2){
				x = pw(x,M-2);
			}
			x%=M;
			op.push_back(z+1);
			if(Pa.count(x)){
				vector<int> fi, se;
				while(x != u){
					fi.push_back(Pa[x].second);
					x = Pa[x].first;
				}
				reverse(op.begin(),op.end());
				reverse(fi.begin(),fi.end());
				cout << fi.size() + op.size() << '\n';
				for(auto y : fi)cout << y << ' ';
				for(auto y : op)cout << y << ' ';
				cout << '\n';

					
				return 0;
			}
		}


	}
}