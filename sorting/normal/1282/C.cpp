#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 7;

array<long long, 3> arr[MAXN];
long long a_cnt, b_cnt;

void solve(){
	long long n, m, a, b;
	cin >> n >> m >> a >> b;

	for(long long i = 0; i < n; ++i){
		bool b;
		cin >> b;
		arr[i][1] = b;

		if(b)
			++b_cnt;
		else
			++a_cnt;
	}
	for(long long i = 0; i < n; ++i){
		cin >> arr[i][0];
		arr[i][2] = i;
	}
	sort(arr, arr + n);

	long long ans = 0, t = 0;
	for(long long i = 0; i < n; ++i){
		if(t < arr[i][0]){
			long long curr = i;
			long long diff = arr[i][0] - t - 1;

			long long a_add = min(a_cnt, diff / a);
			diff -= a_add * a;
			long long b_add = min(b_cnt, diff / b);

			ans = max(ans, curr + a_add + b_add);
		}
		if(arr[i][1]){
			t += b;
			--b_cnt;
		}
		else{
			t += a;
			--a_cnt;
		}
	}

	if(t <= m)
		ans = max(ans, n);

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;
	cin >> t;

	while(t--)
		solve();
}