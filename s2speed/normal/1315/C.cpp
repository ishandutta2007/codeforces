#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll t , n , h;
	vector<ll> b , ans;
	set<ll> a;
	cin>>t;
	while(t > 0){
		t--;
		ans.clear();
		a.clear();
		b.clear();
		cin>>n;
		bool ch = false;
		for(int i = 0 ; i < n ; i++){
			cin>>h;
			ans.push_back(h);
			b.push_back(h);
		}
		sort(b.begin() , b.end());
		for(int i = 0 ; i < n ; i++){
			if(b[i] > 2 * i + 1){
				cout<<-1<<endl;
				ch = true;
				break;
			}
		}
		if(ch == true){
			continue;
		}
		for(int i = 1 ; i <= 2 * n ; i++){
			a.insert(i);
		}
		for(int i = 0 ; i < n ; i++){
			a.erase(a.find(b[i]));
		}
		for(int i = 0 ; i < n ; i++){
			cout<<ans[i]<<" ";
			for(int j = ans[i] + 1 ; ; j++){
				if(a.find(j) != a.end()){
					cout<<j<<" ";
					a.erase(a.find(j));
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}