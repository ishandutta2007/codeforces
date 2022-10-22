#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	ll u , v , w , t;
	cin>>u>>v;
	if(u > v){
		cout<<-1<<endl;
		return 0;
	}
	if(u % 2 != v % 2){
		cout<<-1<<endl;
		return 0;
	}
	if(v == 0){
		cout<<0<<endl;
		return 0;
	}
	if(u == v){
		cout<<1<<endl;
		cout<<u<<endl;
		return 0;
	}
	w = (v - u) / 2;
	t = u & w;
	if(t == 0){
		cout<<2<<endl;
		cout<<u + w<<" "<<w<<endl;
	} else {
		cout<<3<<endl;
		cout<<u<<" "<<(v - u) / 2<<" "<<(v - u) / 2<<endl;
	}
	return 0;
}