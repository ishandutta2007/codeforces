#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool pal(string s){
	string h = s;
	reverse(h.begin() , h.end());
	if(s == h){
		return true;
	} else {
		return false;
	}
}

string r(string s){
	string h = s;
	reverse(h.begin() , h.end());
	return h;
}

int main(){
	int p = -1;
	set<int> s;
	vector<int> dt;
	vector<string> v;
	string h;
	ll n , m;
	cin>>n>>m;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		v.push_back(h);
	}
	for(int i = 0 ; i < n ; i++){
		if(s.find(i) != s.end()){
			continue;
		}
		for(int j = i + 1 ; j < n ; j++){
			if(r(v[j]) == v[i] && s.find(j) == s.end()){
				dt.push_back(i * 1e4 + j);
				s.insert(i);
				s.insert(j);
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(pal(v[i]) == true && s.find(i) == s.end()){
			p = i;
			break;
		}
	}
	if(p == -1){
		cout<<dt.size() * 2 * m<<endl;
	} else {
		cout<<(dt.size() * 2 + 1) * m<<endl;
	}
	for(int i = 0 ; i < dt.size() ; i++){
		cout<<v[dt[i] % 10000];
	}
	if(p != -1){
		cout<<v[p];
	}
	for(int i = dt.size() - 1 ; i >= 0 ; i--){
		cout<<v[dt[i] / 10000];
	}
	cout<<endl;
	return 0;
}