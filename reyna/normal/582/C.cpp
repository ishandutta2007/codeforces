//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e5 + 9;
int a[N];
int g[N];
int best[N], is[N], isblock[N];
int sumg[N], val[N], circle[N];
int sum[N];
vector<int> v;
int32_t main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0 && i != n)
			v.push_back(i);
//		if (__gcd(n, i) == 1)
//			g[i]++;
//		sumg[i] = sumg[i - 1] + g[i];
//		val[i] = val[i - 1] + sumg[i];
//		circle[i] = sumg[i] * i;
//		cout << i << ' ' << circle[i] << ' ' << sumg[i]<< endl;
	}
	int res = 0;
	for (int k = 0; k < (int) v.size(); ++k) {
		int d = v[k];
		for (int i = 1; i <= n / d; ++i) {
			if (__gcd(n / d, i) == 1)
				g[i] = 1;
			else
				g[i] = 0;
			sumg[i] = sumg[i - 1] + g[i];
			val[i] = val[i - 1] + sumg[i];
			circle[i] = sumg[i] * i;
		//	cout << i << ' ' << circle[i] << ' ' << sumg[i]<< endl;
		}
		for (int i = 0; i < d; ++i)
			best[i] = 0;
		int p = 0;
		for (int i = 0; i < n; ++i) {
			best[p] = max(best[p], a[i]);
			p++;
			if (p == d)
				p = 0;	
		}
		int s = 0;
		for (int i = 0; i < 2 * n; ++i) {
			is[s] = (best[p] == a[s]), sum[i + 1] = sum[i] + is[s];
			p++;
			s++;
			if (s == n)
				s = 0;
			if (p == d)
				p = 0;
		}
		int b = n / d;
		for (int st = 0; st < d; ++st) {
			int s = st, e = (st + d);
			for (int i = 0; i < b; ++i) {
				if (sum[e] - sum[s] == d) {
			//		cout << st << ' ' << d << ' ' << s << ' ' << e << ' ' << d << endl;
					isblock[i] = 1;
				} else
					isblock[i] = 0;
				s = s + d, e = e + d;
			}
			int sar = 0;
			for (int i = 0; i < b; ++i)
				if (!isblock[i])
					break;
				else
					sar++;
			if (sar == b) {
				res += circle[b];
				continue;
			}
			int tah = b, cnt = 0;
			for (int i = b - 1; ~i; --i)
				if (!isblock[i])
					break;
				else
					tah--, cnt++;
			res += val[cnt + sar];
	//		cout << sar << ' ' << tah << ' ' << cnt << ' ' << val[2] << ' ' << d << endl;
			cnt = 0;
			for (int i = sar; i < tah; ++i) {
				if (isblock[i])
					cnt++;
				else {
					res += val[cnt];
					cnt = 0;
				}
			}
			res += val[cnt];
			
		}
	}
	cout << res << endl;
	return 0;
		
		
}