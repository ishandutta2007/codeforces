#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;

vector<long long> v[MAXN];
bool up[MAXN];
long long cnt_start[MAXN], cnt_end[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	for(long long i = 0; i < n; ++i){
		long long sz;
		cin >> sz;

		for(long long j = 0; j < sz; ++j){
			long long x;
			cin >> x;
			v[i].push_back(x);
		}
	}

	long long cnt_up = 0;
	for(long long i = 0; i < n; ++i){
		for(long long j = 0; j < (long long)v[i].size() - 1; ++j){
			if(v[i][j] < v[i][j + 1]){
				up[i] = true;
				++cnt_up;
				break;
			}
		}
	}

	long long ans = n * n - (n - cnt_up) * (n - cnt_up), sum_end = 0;
	for(int i = 0; i < n; ++i){
		if(up[i])
			continue;
		++cnt_start[v[i][0]];
		++sum_end;
		++cnt_end[v[i].back()];
	}

	for(int i = MAXN - 1; i >= 0; --i){
		sum_end -= cnt_end[i];
		ans += cnt_start[i] * sum_end;
	}

	cout << ans << "\n";

	return 0;
}