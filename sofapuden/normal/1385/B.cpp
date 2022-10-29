#include <bits/stdc++.h>

using namespace std;

int  main(){
	
	int t; cin >> t;
	while(t--){
		set<int> S;
		int n; cin >> n;
		n*=2;
		while(n--){
			int x; cin >> x;
			if(!S.count(x)){
				cout << x << " ";
			}
			S.insert(x);
		}
		cout << "\n";
	}
	
	
	return 0;
}