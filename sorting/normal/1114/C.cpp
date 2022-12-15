#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

long long mn = inf;
long long n, b;

void solve(long long x, long long cnt){
	long long n2 = n;
	long long res = 0;

	while(n2 > 0){
		res += n2 / x;
		n2 /= x;
	}

	mn = min(res / cnt, mn);

	//cout << x << " " << res << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> b;

	long long b2 = b;

	for(long long i = 2; i*i <= b2; i++){
		if(b2 % i == 0){
			long long cnt = 0;

			while(b2 % i == 0){
				b2 /= i;
				cnt++;
			}

			solve(i, cnt);	
		}
	}
	if(b2 != 1){
		solve(b2, 1);
	}

	cout << mn << "\n";

	return 0;
}