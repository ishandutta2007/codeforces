#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

bool z;

void ch(){
	if(z == true){
		z = false;
	} else {
		z = true;
	}
}

int main(){
	int n , m , l = 0 , counter = 0;
	bool s;
	string a , b;
	cin>>a>>b;
	n = b.size();
	m = a.size();
	for(int i = 0 ; i < n ; i++){
		if(b[i] == '1'){
			l++;
		}
	}
	s = l % 2;
	l = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i] == '1'){
			l++;
		}
	}
	if(l % 2 == s){
		z = true;
		counter++;
	}
	for(int j = n ; j < m ; j++){
		if(a[j] != a[j - n]){
			ch();
		}
		if(z == true){
			counter++;
		}
	}
	cout<<counter<<endl;
	return 0;
}