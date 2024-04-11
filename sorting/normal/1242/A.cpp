#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	long long x = n, cnt = 0, div = -1;
	for(long long i = 2; i * i <= x; ++i){
		if(x % i == 0){
			++cnt;
			div = i;

			while(x % i == 0){
				x /= i;
			}
		}
	}

	if(x != 1){
		++cnt;
		div = x;
	}

	if(cnt == 1 && div == n){
		cout << n << "\n";
		return 0;
	}

	if(cnt == 1){
		cout << div << "\n";
	}
	else{
		cout << 1 << "\n";
	}

	return 0;
}