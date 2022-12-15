#include <bits/stdc++.h>

using namespace std;

const long long kMod = 998244353;
const int kN = 2e5 + 7;

long long a[kN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	long long sum = (n + (n - k + 1ll)) * k / 2;

	int pr = -1;
	long long cnt = 1;
	for(int i = 0; i < n; ++i){
		if(a[i] >= n - k + 1){
			if(pr == -1){
				pr = i;
				continue;
			}

			cnt *= (i - pr);
			cnt %= kMod;
			pr = i;
		}
	} 

	cout << sum << " " << cnt << "\n";
}