#include <bits/stdc++.h>

using namespace std;

const long long mx = 1e9;

bool query(long long x, long long y){
	cout << "? "<<  x << " " << y << "\n";
	fflush(stdout);

	char s;

	cin >> s;

	if(s == 'e')
		exit(0);

	if(s == 'x')
		return true;

	return false;
}

long long solve(){
	if(query(0, 1))
		return 1;

	long long l = 1;
	long long curr = 1;
	bool big = true;

	while(true){
		bool q = query(l, l + curr);

		if(q){
			if(curr == 1){
				return l+1;
			}

			big = false;
			curr /= 2;
		}else{
			if(big){
				curr *= 2;
				l *= 2;
			}else{
				l += curr;
				if(curr > 1){
					curr /= 2;
				}else{
					return l+1;
				}
			}
		}
	}

	return -1;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);

	string s;

	do{
		cin >> s;

		if(s != "start")
			break;

		long long ans = solve();

		cout << "! " << ans << "\n";
		fflush(stdout);
	}
	while(true);

	return 0;
}