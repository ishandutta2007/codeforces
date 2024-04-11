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

vector< pair<ll , ll> >  t;
vector< ll > v[500001];
set< ll > s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , m , a , b;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>a>>b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for(int i = 0 ; i < n ; i++){
		cin>>a;
		t.push_back(make_pair(a , i));
	}
	for(int i = 0 ; i < n ; i++){
		s.clear();
		for(int j = 0 ; j < v[i].size() ; j++){
			if(t[v[i][j]].first == t[i].first){
				cout<<-1<<endl;
				return 0;
			} else if(t[v[i][j]].first < t[i].first) {
				s.insert(t[v[i][j]].first);
			}
		}
		if(s.size() < t[i].first - 1){
			cout<<-1<<endl;
			return 0;
		}
	}
	sort(t.begin() , t.end());
	for(int i = 0 ; i < n ; i++){
		cout<<t[i].second + 1<<" ";
	}
	cout<<"\n";
	return 0;
}