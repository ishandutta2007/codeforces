#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 411111

#define TASK "1"

using namespace std;

long long ans = 1e18;

int n;
int a[1000111];


void check(long long m) {
	long long cnt1 = 0;
	long long sum1 = 0;
	long long cnt2 = 0;
	long long sum2 = 0;
	int pos = -1;

	long long cnt = 0;

	long long ret = 0;
	for (int i = 0; i < n; i++) {
		long long v = a[i] % m;

		vector<long long> parts;
		int q = v / 3;
		parts.pb(v / 3);
		parts.pb((v - v / 3) / 2);
		parts.pb((v - v / 3 + 1) / 2);

		for (long long v : parts) {


			if (cnt + v < (m + 1) / 2) {
				cnt += v;
				cnt1 += v;
				sum1 += i * v;
			} else if (cnt < (m + 1) / 2 && cnt + v >= (m + 1) / 2) {
				pos = i;
				long long left = cnt + v - (m + 1) / 2;
				cnt += v;
				cnt1 += v - left;
				sum1 += (v - left) * i;
				cnt2 = left;
				sum2 = left * i;
			} else if (cnt >= (m + 1) / 2 && cnt + v < m) {
				cnt += v;
				cnt2 += v;
				sum2 += i * v;			
			} else {
				long long left = cnt + v - m;
	
				cnt2 += v - left;
				sum2 += (v - left) * i;
	
				ret += pos * 1ll * cnt1 - sum1;
				ret += sum2 - pos * 1ll * cnt2;

				cnt = left;
				cnt1 = left;
				sum1 = left * i;
				cnt2 = sum2 = 0;
			}
		}

	}
	cerr << m << " " << ret << endl;
	ans = min(ans, ret);
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
	if (sum == 1) {
		cout << -1 << endl;
		return 0;
	}
	long long x = sum;
	for (int d = 2; d * 1ll * d <= x; d++) if (x % d == 0) {
		check(d);
		while (x % d == 0) x /= d;
	}
	if (x > 1) check(x);
	cout << ans << endl;
	return 0;
}