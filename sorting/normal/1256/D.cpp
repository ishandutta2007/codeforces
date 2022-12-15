#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int first = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == '1'){
			continue;
		}

		if(i - first > k){
			swap(s[i], s[i - k]);
			break;
		}
		swap(s[i], s[first]);
		k -= i - first;
		++first;
	}

	cout << s << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}