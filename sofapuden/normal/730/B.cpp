#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 1){
			cout << "! 1 1" << endl;
			continue;
		}
		cout << "? 1 2" << endl;
		char c; cin >> c;
		int mx, mn;
		if(c == '>')mx = 1, mn = 2;
		else mx = 2, mn = 1;
		for(int i = 2; i <= n/2; ++i){
			cout << "? " << 2*i << " " << 2*i-1 << endl;
			cin >> c;
			if(c == '>'){
				cout << "? " << 2*i << " " << mx << endl;
				cout << "? " << 2*i-1 << " " << mn << endl;
				cin >> c;
				if(c == '>')mx = 2*i;
				cin >> c;
				if(c == '<')mn = 2*i-1;
			}
			else{
				cout << "? " << 2*i-1 << " " << mx << endl;
				cout << "? " << 2*i << " " << mn << endl;
				cin >> c;
				if(c == '>')mx = 2*i-1;
				cin >> c;
				if(c == '<')mn = 2*i;
			}
		}
		if(n&1){
			cout << "? " << n << " " << mx << endl;
			cout << "? " << n << " " << mn << endl;
			cin >> c;
			if(c == '>')mx = n;
			cin >> c;
			if(c == '<')mn = n;
		}
		cout << "! " << mn << " " << mx << endl;
	}
}