#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 7007;

pair<long long, long long> p[MAXN];
bool used[MAXN];
//map<long long, long long> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 0; i < n; ++i){
		cin >> p[i].first;
		//++mp[p[i].first];
	}
	for(long long i = 0; i < n; ++i){
		cin >> p[i].second;
	}

	sort(p, p + n);

	long long ans = 0;

	for(int i = 1; i < n; ++i){
		if(p[i].first == p[i - 1].first && (i == n - 1 || p[i].first != p[i + 1].first)){
			for(int j = i; j >= 0; --j){
				if(used[j]){
					continue;
				}

				if(p[j].first == (p[i].first & p[j].first)){
					ans += p[j].second;
					used[j] = true;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}