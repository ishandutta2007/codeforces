#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b; cin >> a >> b;
	for(int i = 0;; ++i){
		if(i&1){
			a-=i;
		}
		else{
			b-=i;
		}
		if(a < 0 || b < 0){
			cout << (i&1 ? "Vladik" : "Valera") << "\n";
			break;
		}

	}
}