#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 7;
const int inf = 1e9 + 7;

int a[N];
map<int, int> mp;

int prefix[N], suffix[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, I;

	cin >> n >> I;

	I *= 8;

	for(int i = 0; i < n; i++){
		cin >> a[i];

		++mp[a[i]];
	}

	int i = 1;
	for(auto it = mp.begin(); it != mp.end(); ++it, ++i){
		prefix[i] = prefix[i - 1] + it->second;
		//cout << prefix[i] << " prefix " << i << endl;
	}

	int m = (int)mp.size();

	i = m;
	for(auto it = --mp.end(); true; it--, i--){
		suffix[i] = suffix[i + 1] + it->second;
		//cout << suffix[i] << " suffix " << i << endl;
		if(it == mp.begin()){
			break;
		}
	}

	int k = 0;

	while((1 << k) < m){
		++k;
	}

	if(n * k <= I){
		cout << "0\n";

		return 0;
	}

	while(n * k > I){
		k--;
	}

	int K = m - (1 << k);
	int ans = inf;

	for(int i = 0; i <= K; i++){
		ans = min(ans, prefix[i] + suffix[m - (K - i) + 1]);
	}

	cout << ans << "\n";

	return 0;
}