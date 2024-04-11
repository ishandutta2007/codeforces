#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

long long p[MAXN];
long long n, x, a, y, b, k;

bool check(long long cnt){
	long long cnt_xy = cnt / (a * b / __gcd(a, b));
	long long cnt_x = (cnt / a) - cnt_xy;
	long long cnt_y = (cnt / b) - cnt_xy;
	long long ans = 0;

	//cout << cnt << " - " << cnt_xy << " " << cnt_x << " " << cnt_y << endl;  

	for(int i = n; i >= n - cnt + 1 && i >= 1 && ans < k; --i){
		//cout << ans << " a" << endl;
		if(cnt_xy){
			ans += (x + y) * p[i];
			--cnt_xy;
			continue;
		}
		if(cnt_x){
			ans += x * p[i];
			--cnt_x;
			continue;
		}
		if(cnt_y){
			ans += y * p[i];
			--cnt_y;
			continue;
		}

	}

	//cout << ans << " ans" << endl;

	return ans >= k;
}

void solve(){
	cin >> n;

	for(long long i = 1; i <= n; ++i){
		cin >> p[i];
		p[i] /= 100;
	}
	sort(p + 1, p + n + 1);

	cin >> x >> a >> y >> b >> k;

	if(x < y){
		swap(x, y);
		swap(a, b);
	}

	long long l = 0, r = n + 1;
	while(l != r){
		long long mid = (l + r) >> 1;

		//cout << l << " - " << r << endl;

		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	if(l == n + 1){
		cout << "-1\n";
	}
	else{
		cout << l << "\n";
	}

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long q;

	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}