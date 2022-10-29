#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int x, y; cin >> x >> y;
	for(int i = 1; i <= x; ++i){
		if(i%2){
			for(int j = 0; j < y; j++){
				cout << '#';
			}
			cout << '\n';
		}
		else{
			if(i%4 == 0){
				cout << '#';
			}
			for(int j = 0; j < y-1; j++){
				cout << '.';
			}
			if(i%4){
				cout << '#';
			}
			cout << '\n';
		}
	}
	
}