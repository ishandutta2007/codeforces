#include <bits/stdc++.h>

using namespace std;

int cnt_s[256], cnt_t[256];

void solve(){
	int n;
	string s, t;

	cin >> n;
	cin >> s >> t;
	for(int i = 'a'; i <= 'z'; ++i){
		cnt_s[i] = 0;
		cnt_t[i] = 0;
	}

	for(char c: s){
		++cnt_s[c];
	}
	for(char c: t){
		++cnt_t[c];
	}

	bool twice = false;
	for(int i = 'a'; i <= 'z'; ++i){
		if(cnt_s[i] != cnt_t[i]){
			cout << "NO\n";
			return;
		}
		if(cnt_s[i] >= 2){
			twice = true;
		}
	}

	if(twice){
		cout << "YES\n";
		return;
	}

	for(int i = 'a'; i <= 'z'; ++i){
		cnt_s[i] = 0;
		cnt_t[i] = 0;
	}

	for(int i = 0; i < n; ++i){
		cnt_s[s[i]] = i;
		cnt_t[t[i]] = i;
	}

	long long sum_t = 0, sum_s = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			if(s[i] > s[j]){
				++sum_t;
			}
			if(t[i] > t[j]){
				++sum_s;
			}
		}
	}

	if((sum_t & 1) != (sum_s & 1)){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
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