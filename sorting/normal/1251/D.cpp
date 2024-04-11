#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 7;
const long long inf = 1e9;

pair<long long, long long> p[MAXN];
bool used[MAXN];
long long n, s;

bool check(long long mid){
	long long l = 0, cost = 0;
	for(int i = 0; i < n; ++i){
		used[i] = false;
		cost += p[i].first;
		if(p[i].second < mid){
			++l;
			used[i] = true;
		}
	}
	if(l > n / 2){
		return false;
	}

	
	for(int i = 0; i < n; ++i){
		if(!used[i]){
			if(l >= n / 2){
				if(mid > p[i].first){
					cost += mid - p[i].first;
				}
			}
			++l;
		}
	}

	return cost <= s;
}

void solve(){
	cin >> n >> s;

	for(int i = 0; i < n; ++i){
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);

	long long l = 1, r = inf;
	while(l != r){
		long long mid = (l + r + 1) >> 1ll;

		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}

	cout << l << "\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;

	cin >> t;

	while(t--){
		solve();
	}
	return 0;
}