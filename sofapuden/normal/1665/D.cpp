#include<bits/stdc++.h>

using namespace std;

int que(int a, int b){
	cout << "? " << a << ' ' << b << endl;
	int x; cin >> x;
	return x;
}

int main(){
	int t; cin >> t;
	while(t--){
		int cu = 0;
		for(int i = 1; i < 30; ++i){
			int x = que((1<<i)-cu,(1<<(i+1))-cu);
			if(x == 1<<(i-1)){
				cu+=(1<<(i-1));
			}
		}
		int x = que(1,2+cu+(1<<29));
		if(x == 1+cu+(1<<29))cu+=(1<<29);
		cout << "! " << cu << endl;
	}
}