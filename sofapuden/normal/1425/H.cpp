#include <bits/stdc++.h>

using namespace std;

int main(){
	int T; cin >> T;
	while(T--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if((a+b)&1){
			if(a||d){
				cout << "Ya ";
			}
			else{
				cout << "Tidak ";
			}
			if(b||c){
				cout << "Ya ";
			}
			else{
				cout << "Tidak ";
			}
			cout << "Tidak Tidak" << "\n";
		}
		else{
			cout << "Tidak Tidak ";
			if(b||c){
				cout << "Ya ";
			}
			else{
				cout << "Tidak ";
			}
			if(a||d){
				cout << "Ya ";
			}
			else{
				cout << "Tidak ";
			}
			cout << "\n";
		}
	}
}