#include <bits/stdc++.h>

using namespace std;

int  main(){
	int t; cin >> t;
	while(t--){
		vector<int> vi(3);
		for(int &i : vi){
			cin >> i;
		}
		sort(vi.rbegin(),vi.rend());
		if(vi[0] == vi[1]){
			cout << "YES\n";
			cout << vi[0] << " " << vi[2] << " " << 1 << "\n";
			continue;
		}
		cout << "NO\n";
		
	}
	return 0;
}