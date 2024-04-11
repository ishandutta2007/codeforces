#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll MAX_N = 2e5;

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

bool gh[1000000];

ll r = 1e6;

void gh_build(){
	gh[1] = false;
	for(int i = 2 ; i < r ; i++){
		gh[i] = true;
	}
	for(int i = 2 ; i < r ; i++){
		if(gh[i] == true){
			for(int j = i * 2 ; j < r ; j += i){
				gh[j] = false;
			}
		}
	}
	return;
}

vector<ll> divis , pridiv;
set<ll> di;

void get_div(ll n){
	double p = sqrt(n);
	divis.push_back(n);
	di.insert(n);
	for(int i = 2 ; i <= p ; i++){
		if(n % i == 0){
			di.insert(i);
			divis.push_back(i);
			if(i != p){
				di.insert(n / i);
				divis.push_back(n / i);
			}
		}
	}
}

ll count_div(ll n){
	ll p = sqrt(n) , counter = 0;
	for(int i = 1 ; i <= p ; i++){
		if(n % i == 0){
			counter++;
			if(i != p){
				counter++;
			}
		}
	}
	return counter;
}

bool mark[MAX_N];

void solve(){
	ll n;
	cin>>n;
	get_div(n);
	ll ds = divis.size();
	for(int i = 0 ; i < ds ; i++){
		mark[i] = false;
		if(divis[i] < 1e6){
			if(gh[divis[i]] == true){
				mark[i] = true;
				pridiv.push_back(divis[i]);
			}
		} else {
			ll h = count_div(divis[i]);
			if(h == 2){
				mark[i] = true;
				pridiv.push_back(divis[i]);
			}
		}
	}
	ll pds = pridiv.size();
	if(ds == 3 && pds == 2){
		cout<<divis[0]<<" "<<divis[1]<<" "<<divis[2]<<"\n1\n";
		divis.clear();
		pridiv.clear();
		di.clear();
		return;
	}
	if(pds == 1){
		for(int i = 0 ; i < ds ; i++){
			cout<<divis[i]<<" ";
		}
		cout<<"\n";
	} else if(pds == 2){
		cout<<pridiv[0]<<" ";
		for(int i = 0 ; i < ds ; i++){
			if(divis[i] % (pridiv[0] * pridiv[1]) == 0 && divis[i] != pridiv[0] * pridiv[1] && mark[i] == false){
				mark[i] = true;
				cout<<divis[i]<<" ";
			}
		}
		cout<<pridiv[1]<<" ";
		for(int i = 0 ; i < ds ; i++){
			if(divis[i] % (pridiv[0] * pridiv[1]) != 0 && divis[i] % pridiv[1] == 0 && mark[i] == false){
				mark[i] = true;
				cout<<divis[i]<<" ";
			}
		}
		cout<<pridiv[1] * pridiv[0]<<" ";
		for(int i = 0 ; i < ds ; i++){
			if((!mark[i]) && divis[i] != pridiv[1] * pridiv[0]){
				mark[i] = true;
				cout<<divis[i]<<" ";
			}
		}
		cout<<"\n";
	} else {
		for(int i = 0 ; i < pds ; i++){
			cout<<pridiv[i]<<" ";
			ll h = pridiv[i] * pridiv[(i + 1) % pds];
			for(int j = 0 ; j < ds ; j++){
				if(divis[j] % pridiv[i] == 0 && mark[j] == false && divis[j] % pridiv[(i + 1) % pds] != 0 && divis[j] % pridiv[(i - 1 + pds) % pds]){
					mark[j] = true;
					cout<<divis[j]<<" ";
				}
			}
			for(int j = 0 ; j < ds ; j++){
				if(divis[j] % h == 0 && mark[j] == false){
					mark[j] = true;
					cout<<divis[j]<<" ";
				}
			}
		}
		cout<<"\n";
	}
	cout<<"0\n";
	divis.clear();
	di.clear();
	pridiv.clear();
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	gh_build();
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}