#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

set<int> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		int x;

		cin >> x;

		st.insert(x);
	}

	int ans = 0;
	while(!st.empty()){
		int x = *st.begin();
		st.erase(x);
		for(int i = x; i <= 100; i += x){
			if(st.count(i)){
				st.erase(i);
			}
		}
		++ans;
	}

	cout << ans << "\n";

	return 0;
}