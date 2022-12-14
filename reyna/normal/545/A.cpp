//In the name of God
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n;i++){
		int f = 0;
		for(int j = 0; j < n;j++){
			int p;
			cin >> p;
			if(p == 1 || p == 3) f = 1;
		}
		if(!f) ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size();i++) cout << ans[i] << ' ';
	return 0;
}