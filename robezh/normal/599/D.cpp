#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

ll t;
vector<P> res;

int main(){
	cin >> t;
	ll up = (ll)(pow(t,0.33333334) * pow(3,0.33333334)) + 1;
	//cout << up;
	for(ll i = 1; i <= up; i++){
		if((6 * t) % (i * (i+1)) == 0){
			if((6*t/(i*(i+1))+i-1) % 3 == 0){
				ll m = (6*t/(i*(i+1))+i-1) / 3;
				//cout << m;
				if(m >= i){
					res.push_back(P(i,m));
				}	
			}
		}
	}
	P last = res[res.size()-1];
	if(last.first == last.second) cout << res.size() * 2 - 1 << endl;
	else cout << res.size() * 2 << endl;
	for(int i = 0; i < res.size(); i++){
		cout << res[i].first << " " << res[i].second << endl;
	}
	for(int i = (int)res.size() - 1; i >= 0; i--){
		if(res[i].first != res[i].second)
		cout << res[i].second << " " << res[i].first << endl;
	}
	return 0;
}