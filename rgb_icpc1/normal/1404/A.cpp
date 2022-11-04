#include<bits/stdc++.h>

using namespace std;
char s[500005];
int main(){


	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int t, n, k;
	for(cin >> t; t --;){
		cin >> n >> k;
		cin >> s;
		int ok = 0;
		for(int i = 0; i < n - k; i ++) {
			if(s[i] == '?'|| s[i + k] == '?') {
				if(s[i] == '?') s[i] = s[i + k];
				else s[i + k] = s[i];
			}
			else if(s[i] != s[i + k]) {
				ok = 1;
				break;
			}
		}
		for(int j = n - 1; j >= k; j --){
			int i = j - k;
			if(s[i] == '?'|| s[i + k] == '?') {
				if(s[i] == '?') s[i] = s[i + k];
				else s[i + k] = s[i];
			}
			else if(s[i] != s[i + k]) {
				ok = 1;
				break;
			}
		}
		if(ok){
			cout << "NO" << endl;
			continue;
		}
		int n0 = 0, n1 = 0;
		for(int i = 0; i < k;i ++) {
			if(s[i] == '0') n0++;
			else if(s[i] == '1') n1 ++;
		}
		if(n0 <= k / 2&& n1 <= k / 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}