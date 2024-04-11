#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int LOGN = 21;
const int MAXN = (1 << LOGN);

int a[MAXN], f[MAXN], power[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);

	for(int i = 0; i < n; ++i){
		f[a[i]]++;
	}

	for(int i = 0; i < LOGN; ++i){
		for(int j = 0; j < MAXN; ++j){
			if((j & (1 << i)) == 0){
				f[j] += f[j | (1 << i)];
				f[j] %= mod;
			}
		}
	}

	power[0] = 1;
	for(int i = 1; i < MAXN; ++i){
		power[i] = (power[i - 1] * 2) % mod;
	}

	int ans = 0;
	for(int i = 0; i < MAXN; ++i){
		int cnt = 0;
		for(int j = 0; j < LOGN; ++j){
			cnt += (bool)(i & (1 << j));
		}

		if(cnt & 1){
			ans += (mod - power[f[i]]);
			ans %= mod;
		}
		else{
			ans += power[f[i]];
			ans %= mod;
		}
	}

	cout << ans << "\n";
}