#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int a[MAXN];
set<int> st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}

	int ans = n;

	for(int i = 0; i <= n; ++i){
		bool ok = true;
		st.clear();
		for(int j = 1; j <= i; ++j){
			if(st.count(a[j])){
				ok = false;
				break;
			}
			st.insert(a[j]);
		}

		if(!ok){
			continue;
		}

		int j = n;

		for(j = n; j > i; --j){
			if(st.count(a[j])){
				break;
			}
			st.insert(a[j]);
		}

		ans = min(ans, (j - i));
	}

	cout << ans << "\n";

	return 0;
}