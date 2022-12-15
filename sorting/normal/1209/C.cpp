#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;

	cin >> n;

	string s;

	cin >> s;

	for(int i = '0'; i <= '9'; ++i){
		int pr1 = '0', pr2 = '0';
		bool ok = true;
		for(int j = 0; j < n; ++j){
			if(s[j] <= i){
				if(s[j] < pr1){
					ok = false;
					break;
				}
				pr1 = s[j];
			}
			else{
				if(s[j] < pr2){
					if(s[j] == i + 1){
						pr1 = s[j];
						continue;
					}
					ok = false;
					break;
				}
				pr2 = s[j];
			}
		}
		if(!ok){
			continue;
		}

		pr1 = '0', pr2 = '0';
		for(int j = 0; j < n; ++j){
			if(s[j] <= i){
				cout << "1";
				pr1 = s[j];
			}
			else{
				if(s[j] < pr2){
					if(s[j] == i + 1){
						cout << "1";
						pr1 = s[j];
						continue;
					}
				}
				cout << "2";
				pr2 = s[j];
			}
		}
		cout << "\n";
		return;
	}

	cout << "-\n";
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