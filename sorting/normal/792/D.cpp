#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, q;

	cin >> n >> q;

	while(q--){
		long long u;
		string s;

		cin >> u >> s;

		for(long long i = 0; i < s.size(); i++){
			//cout << u << " "; 
			if(s[i] == 'U'){
				if(u == (n + 1ll) >> 1ll){
					continue;
				}


				long long v = u, cnt = 0;

				while(v % 2ll == 0){
					v /= 2ll;
					cnt++;
				}

				if(v % 4 == 1){
					u += (long long)(1ll << cnt);
				}
				else{
					u -= (long long)(1ll << cnt);
				}

				continue;
			}
			if(s[i] == 'L'){
				long long v = u, cnt = 0;

				while(v % 2ll == 0){
					v /= 2ll;
					cnt++;
				}

				if(cnt == 0){
					continue;
				}

				u -= (long long)(1ll << (cnt - 1ll));

				continue;
			}
			if(s[i] == 'R'){
				long long v = u, cnt = 0ll;

				while(v % 2ll == 0){
					v /= 2ll;
					cnt++;
				}

				if(cnt == 0ll){
					continue;
				}

				u += (long long)(1ll << (cnt - 1ll));

				continue;
			}
		}

		cout << u << "\n";
	}
}