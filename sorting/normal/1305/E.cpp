#include <bits/stdc++.h>

using namespace std;

const int kN = 10007;

int cnt[kN];

long long mx(long long n){
	long long k = n / 2;
	--k;
	if(n & 1)
		return (k + 1) * (k + 1);
	return k * (k + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m;
	cin >> n >> m;

	if(mx(n) < m){
		cout << "-1\n";
		return 0;
	}
 
	long long i = 1;
	for(; i <= n; ++i)
		if(mx(i) > m)
			break;
	--i;

	m -= mx(i);
	if(i == n){
		for(int j = 1; j <= n; ++j)
			cout << j << "\n";
		return 0;
	}

	for(int j = 1; j <= i; ++j)
		for(int k = j + 1; k <= i; ++k)
			++cnt[k + j];

	int which = -1;
	for(int j = i + 1; j < kN; ++j){
		if(cnt[j] == m){
			which = j;
			break;
		}
	}

	if(which == -1){
		cout << "-1\n";
		return 0;
	}

	int diff = 20000;
	for(int j = 1; j <= i; ++j)
		cout << j << " ";
	cout << which << " ";
	for(int j = i + 2; j <= n; ++j)
		cout << diff + (diff + 1) * (j - i - 2) << " ";
	cout << "\n";
}