#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int x = 0, y = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'G')x = i;
		if(s[i] == 'T')y = i;
	}
	while(x > y){
		x-=k;
		if(x < y || s[x] == '#'){
			x+=k;
			break;
		}
	}
	while(x < y){
		x+=k;
		if(x > y || s[x] == '#'){
			x-=k;
			break;
		}
	}
	cout << (x == y ? "YES\n" : "NO\n");
}