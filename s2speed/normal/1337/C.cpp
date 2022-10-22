#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

ll mk(ll a){
	return 0 - a;
}

vector<ll> v[200001] , l[200000] , p;
set<ll> s;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll n , k , u , y , b = 0 , ans = 0;
	cin>>n>>k;
	for(int i = 1 ; i < n ; i++){
		p.push_back(0);
		cin>>u>>y;
		v[u].push_back(y);
		v[y].push_back(u);
	}
	p.push_back(0);
	p.push_back(0);
	s.insert(1);
	l[0].push_back(1);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < l[i].size() ; j++){
			for(int q = 0 ; q < v[l[i][j]].size() ; q++){
				if(s.find(v[l[i][j]][q]) == s.end()){
					l[i + 1].push_back(v[l[i][j]][q]);
					s.insert(v[l[i][j]][q]);
				}
			}
		}
		if(s.size() == n){
			b = i + 1;
			break;
		}
	}
	for(int i = 0 ; i < l[b].size() ; i++){
		p[l[b][i]] = 0;
	}
	for(int i = b - 1 ; i >= 0 ; i--){
		for(int j = 0 ; j < l[i].size() ; j++){
			for(int q = 0 ; q < v[l[i][j]].size() ; q++){
				p[l[i][j]] += p[v[l[i][j]][q]] + 1;
			}
			p[l[i][j]]--;
		}
	}
	p[1]++;
	for(int i = 0 ; i <= b ; i++){
		for(int j = 0 ; j < l[i].size() ; j++){
			p[l[i][j]] -= i;
			p[l[i][j]] = mk(p[l[i][j]]);
		}
	}
	p.erase(p.begin());
	sort(p.begin() , p.end());
	reverse(p.begin() , p.end());
	for(int i = 0 ; i < k ; i++){
		ans += p[i];
	}
	cout<<ans<<endl;
	return 0;
}