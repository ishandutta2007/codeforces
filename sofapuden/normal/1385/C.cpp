#include <bits/stdc++.h>

using namespace std;

int  main(){
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n); for(int &i : v)cin >> i;
		int now = 0;
		bool dow = 0;
		int ind = 0;
		for(int i = n-1; i >= 0; --i){
			if(v[i] < now){
				dow = 1;
				now = v[i];
				continue;
			}
			if(v[i] > now && dow){
				ind = i+1;
				break;
			}
			now = v[i];
		}
		cout << ind << "\n"; 
			
			
		
	}
			
	
	return 0;
}