#include <bits/stdc++.h>

using namespace std;

const int R = 107;

string s[R];
vector<char> v;

void solve(){
	int r, c, k;
	cin >> r >> c >> k;

	for(int i = 0; i < r; ++i){
		cin >> s[i];
	}

	int cnt = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(s[i][j] == 'R'){
				++cnt;
			}
		}
	}

	int cnt_small = 0, cnt_big = 0, small = cnt / k;
	cnt_big = cnt % k;
	cnt_small = k - (cnt % k);

	int idx = 0, needed = small;
	for(int i = 0; i < r; ++i){
		string output = "";
		
		if(i % 2 == 1){
			for(int j = c - 1; j >= 0; --j){
				if(!needed){
					if(idx != k - 1){
						++idx;
						if(idx >= cnt_small){
							needed = small + 1;
						}
						else{
							needed = small;
						}
					}
				}
				output += v[idx];
				if(s[i][j] == 'R'){
					--needed;
				}
			}
			reverse(output.begin(), output.end());
		}
		else{
			for(int j = 0; j < c; ++j){
				if(!needed){
					if(idx != k - 1){
						++idx;
						if(idx >= cnt_small){
							needed = small + 1;
						}
						else{
							needed = small;
						}
					}
				}
				output += v[idx];
				if(s[i][j] == 'R'){
					--needed;
				}
			}
		}
		cout << output << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i = 0; i < 26; ++i){
		v.push_back('a' + i);
		v.push_back('A' + i);
	}
	for(int i = 0; i < 10; ++i){
		v.push_back('0' + i);
	}

	int t;
	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}