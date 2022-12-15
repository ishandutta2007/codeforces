#include <bits/stdc++.h>

using namespace std;

int cnt[57];
int cnt_d[2];

void solve(){
	int n;

	cin >> n;

	for(int i = 0; i < 57; ++i){
		cnt[i] = 0;
	}
	cnt_d[0] = 0;
	cnt_d[1] = 0;

	for(int i = 0; i < n; ++i){
		string s;

		cin >> s;

		++cnt[(int)s.size()];
		for(char c: s){
			++cnt_d[c == '1'];
		}
	}

	int cnt_same, cnt_alone;
	cnt_same = cnt_d[0] / 2 + cnt_d[1] / 2;
	cnt_alone = cnt_d[0] % 2 + cnt_d[1] % 2;

	int ans = 0;

	for(int i = 0; i < 57; ++i){
		while(cnt[i]){
			if(i & 1){
				if(cnt_same >= i / 2){
					if(cnt_alone){
						--cnt[i];
						cnt_same -= i / 2;
						cnt_alone -= 1;
						++ans;
					}
					else{
						if(cnt_same >= i / 2 + 1){
							--cnt[i];
							cnt_same -= i / 2 + 1;
							cnt_alone += 1;
							++ans;
						}
						else{
							cout << ans << "\n";
							return;
						}
					}
				}
				else{
					cout << ans << "\n";
					return;
				}
			}
			else{
				if(cnt_same >= i / 2){
					--cnt[i];
					cnt_same -= i / 2;
					++ans;
				}
				else{
					cout << ans << "\n";
					return;
				}
			}
		}
	}

	cout << ans << "\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}