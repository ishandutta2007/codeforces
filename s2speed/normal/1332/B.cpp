#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	vector<ll> v[11] , tp;
	ll t , n , m , h , p[11] , ans[1000];
	p[0] = 2;
	p[1] = 3;
	p[2] = 5;
	p[3] = 7;
	p[4] = 11;
	p[5] = 13;
	p[6] = 17;
	p[7] = 19;
	p[8] = 23;
	p[9] = 29;
	p[10] = 31;
	cin>>t;
	while(t > 0){
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			for(int j = 0 ; j < 11 ; j++){
				if(h % p[j] == 0){
					v[j].push_back(i);
					break;
				}
			}
		}
		for(int i = 0 ; i < 11 ; i++){
			if(v[i].size() > 0){
				tp.push_back(i);
			}
		}
		for(int i = 0 ; i < tp.size() ; i++){
			for(int j = 0 ; j < v[tp[i]].size() ; j++){
				ans[v[tp[i]][j]] = i + 1;
			}
		}
		cout<<tp.size()<<endl;
		for(int i = 0 ; i < n ; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		for(int i = 0 ; i < 11 ; i++){
			v[i].clear();
		}
		tp.clear();
		t--;
	}
	return 0;
}