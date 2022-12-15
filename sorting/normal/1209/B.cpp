#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;

int x[6][6];

clock_t timer = clock();

bool time_left(){
	return (((float)((float)clock() - (float)timer) / (float)CLOCKS_PER_SEC) <= (float)0.8);
}

int a[MAXN], b[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; 

	cin >> n;

	string s;

	cin >> s;

	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i];
	}

	int ans = 0;
	for(int i = 0; i < n; ++i){
		ans += s[i] - '0';
	}
	for(int i = 1; time_left(); ++i){
		int curr = 0;
		for(int j = 0; j < n; ++j){
			if(i >= b[j] && (i - b[j]) % a[j] == 0){
				s[j] = '0' + ('1' - s[j]);
			}

			curr += s[j] - '0';
		}
		//cout << i << " " << curr << endl;
		ans = max(ans, curr);
	}

	cout << ans << "\n";

	return 0;
}