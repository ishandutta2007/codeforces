#include <bits/stdc++.h>

using namespace std;

int cnt[27];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;

	cin >> n >> k;

	string s;
	int cons = 0;

	cin >> s;

	for(int i = 0; i < s.size(); i++){
		if(i == 0 || s[i] != s[i-1]){
			if(i != 0){
				cnt[s[i-1] - 'a'] += cons / k;
			}
			cons = 1;
		}else{
			cons++;
		}
	}

	cnt[s.back() - 'a'] += cons / k;

	int mx = 0;

	for(int i = 0; i < 26; i++)
		mx = max(mx, cnt[i]);

	cout << mx << "\n";

	return 0;
}