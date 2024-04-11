#include <bits/stdc++.h>

using namespace std;

const int LOGN = 20;
const int MAXN = 2e5 + 7;

int z[MAXN];

void solve(){
	string s;

	cin >> s;

	int ret = 0, n = (int)s.size();

	z[0] = (s[0] == '0');
	for(int i = 1; i < n; ++i){
		if(s[i] == '0'){
			z[i] = z[i - 1] + 1;
		}
		else{
			z[i] = 0;
		}
	}

	for(int i = 0; i < n; ++i){
		int curr = 0, j = 0;
		int power = 1;	
		for(; j < LOGN && i - j >= 0; ++j, power *= 2){
			curr += (s[i - j] == '1') * power;

			if(curr == j + 1){
				++ret;
			}
		}

		if(i - j >= 0){
			int x = curr - 1;

			//cout << x << endl;

			if(x < j){
				continue;
			}
			if(z[i - j] >= curr - j){
				ret++;
				//cout << i << " " << j << endl;
			}
		}
	}

	cout << ret << "\n";
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