#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

#define pb push_back

const int mod = 1000000007;

int a[1000100];
int n;

long long solve2(vector<int>& b, bool was) {
	int n = b.size();
	vector<long long> sum(n + 1, 0);
	long long ans = 2e18;
	forn (i, n) {
		sum[i + 1] = sum[i] + b[i];
	}
	long long cur = 0;
	forn (i, n) {
		cur += b[i] * i;
	}
	forn (i, n) {
//		if (!was || i > 0) {
		ans = min(ans, cur);
//		}
		cur += sum[i + 1];
		cur -= sum[n] - sum[i + 1];
	}
	return ans;
}

long long solve(long long k) {
	long long ans = 0;
	long long sum = 0;
	vector<int> b;
	bool was = false;
	forn (i, n) {
		b.pb(a[i] % k);
		sum += b.back();
		if (sum < k) {
			continue;
		}
		sum -= k;
		b.back() -= sum;
		ans += solve2(b, was);
		b.clear();
		if (sum) {
			b.pb(sum);
		}
		was = sum;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    long long sum = 0;
    forn (i, n) {
    	cin >> a[i];
    	sum += a[i];
    }
    if (sum == 1) {
    	cout << -1 << endl;
    	return 0;
    }
    if (n == 1) {
    	cout << 0 << endl;
    	return 0;
    }
	vector<int> p;
    for (long long i = 2; i * i <= sum; ++i) {
    	if (sum % i) {
    		continue;
    	}
    	p.pb(i);
    	while (sum % i == 0) {
    		sum /= i;
    	}
    }
    if (sum > 1) {
    	p.pb(sum);
    }
    long long ans = 2e18;
    forn (i, p.size()) {
    	ans = min(ans, solve(p[i]));
    }
    cout << ans << endl;
}