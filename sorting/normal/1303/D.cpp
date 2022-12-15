#include <bits/stdc++.h>

using namespace std;

const int kMaxM = 1e5 + 7;

long long a[kMaxM];
map<long long, long long> log_mp;

void solve(){
	long long n, m;
	cin >> n >> m;

	vector<long long> cnt(64, 0ll);
	for(int i = 0; i < m; ++i){
		cin >> a[i];
		++cnt[ log_mp[a[i]] ];
	}

	long long sum = 0, ans = 0;
	for(long long i = 0; i < 62; ++i){
		sum += (1ll << i) * cnt[i];
		if((1ll << i) & n){
			if(sum >= (1ll << i)){
				sum -= 1ll << i;
				continue; 
			}
			long long which = -1;
			for(long long j = i + 1; j < 62; ++j){
				if(cnt[j]){
					which = j;
					break;
				}
			}

			if(which == -1){
				cout << "-1\n";
				return;
			}

			--cnt[which];
			for(int j = which - 1; j >= i; --j){
				++cnt[j];
				++ans;
			}
			sum += (1ll << i);
		}
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long curr = 1;
	for(long long i = 0; i < 62; ++i){
		log_mp[curr] = i;
		curr <<= 1ll;
	}

	int t;
	cin >> t;

	while(t--)
		solve();
}