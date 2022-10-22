#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int b[30000];
string s[100005];

int foo(string s){
	int d[3];
	for(int j = 0; j < 3; j++){
		if(j < (int)s.size()) d[j] = s[j] - 'a';
		else d[j] = 26;
	}
	return d[0] * 27 * 27 + d[1] * 27 + d[2];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < 27 * 27 * 27; i++) b[i] = -1;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			b[foo(s[i])] = i;
		}
		bool f = false;
		for(int i = 0; i < n; i++){
			if((int)s[i].size() == 2){
				for(int j = 0; j < 26; j++){
					string t = s[i] + char('a' + j);
					reverse(t.begin(), t.end());
					if(b[foo(t)] >= i) f = true;
				}
			}
			{
				string t = s[i];
				reverse(t.begin(), t.end());
				if(b[foo(t)] >= i) f = true;
			}
			if((int)s[i].size() == 3){
				string t = s[i].substr(0, (int)s[i].size() - 1);
				reverse(t.begin(), t.end());
				if(b[foo(t)] >= i) f = true;
			}
		}
		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}