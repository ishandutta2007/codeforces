#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ll n , h , cr = 0 , cb = 0;
	cin>>n;
	vector<bool> r , b;
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		r.push_back(h);
	}
	for(int i = 0 ; i < n ; i++){
		cin>>h;
		b.push_back(h);
	}
	for(int i = 0 ; i < n ; i++){
		if(r[i] == 0 && b[i] == 1){
			cb++;
		} else if(r[i] == 1 && b[i] == 0){
			cr++;
		}
	}
	if(cr == 0){
		cout<<-1<<endl;
		return 0;
	}
	cout<<1 + cb/ cr<<endl;
	return 0;
}