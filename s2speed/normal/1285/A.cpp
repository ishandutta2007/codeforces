#include<iostream>
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
	string s;
	int n , c = 0 , cc = 0;
	cin>>n>>s;
	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'L'){
			c++;
		} else {
			cc++;
		}
	}
	cout<<c + cc + 1<<endl;
	return 0;
}