#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int in;
	long long mod = 1000000007;
	scanf("%d", &n);
	int a[n];
	int max_val = 0;
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
		max_val = max(max_val, a[i]);
	}
	sort(a, a+n);
	vector<long long> odd, even;
	for(i=0; i<n; i++) {
		if(a[i]%2 == 0) {
			even.push_back(a[i]/2);
		} else {
			odd.push_back(a[i]/2);
		}
	}
	long long evensq[even.size()+1] = {};
	for(i=1; i<=even.size(); i++) {
		evensq[i] = (evensq[i-1]+even[i-1]*even[i-1])%mod;
	}
	long long evensum[even.size()+1] = {};
	for(i=1; i<=even.size(); i++) {
		evensum[i] = (evensum[i-1]+even[i-1])%mod;
	}
	long long oddsq[odd.size()+1] = {};
	for(i=1; i<=odd.size(); i++) {
		oddsq[i] = (oddsq[i-1]+odd[i-1]*odd[i-1])%mod;
	}
	long long oddsum[odd.size()+1] = {};
	for(i=1; i<=odd.size(); i++) {
		oddsum[i] = (oddsum[i-1]+odd[i-1])%mod;
	}
	/*for(i=0; i<=even.size(); i++) {
		printf("%d %d\n", evensq[i], evensum[i]);
	}
	for(i=0; i<=odd.size(); i++) {
		printf("%d %d\n", oddsq[i], oddsum[i]);
	}*/
	int count[max_val+1] = {};
	for(i=0; i<n; i++) {
		count[a[i]]++;
	}
	int sum[max_val+1];
	sum[max_val] = count[max_val];
	sum[max_val-1] = count[max_val-1];
	for(i=max_val-2; i>=1; i--) {
		sum[i] = (sum[i+2]+count[i])%mod;
	}
	vector<int> p;
	for(i=1; i<=max_val; i++) {
		p.push_back(sum[i]);
	}
	long long ans1 = 0;
	for(i=0; i<p.size()-1; i++) {
		int idx;
		idx = upper_bound(even.begin(), even.end(), i/2)-even.begin();
		ans1 = (ans1+((evensq[even.size()]-evensq[idx]-((even.size()-idx)*((((i+1)/2)*((i+1)/2))%mod))%mod+2*mod)%mod*(p[i]+p[i+1]))%mod)%mod;
		//printf("%lld ", ans1);
		idx = upper_bound(odd.begin(), odd.end(), i/2)-odd.begin();
		ans1 = (ans1+((oddsq[odd.size()]-oddsq[idx]+oddsum[odd.size()]-oddsum[idx]-((odd.size()-idx)*(((i/2)*(i/2+1))%mod))%mod+3*mod)%mod*(p[i]+p[i+1]))%mod)%mod;
		//printf("%lld\n", ans1);
	}
	long long fac[n+1] = {1};
	for(i=1; i<=n; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
	long long ans2 = 1;
	for(i=0; i<p.size(); i++) {
		if(i == 0) {
			ans2 = (ans2*fac[p[i]])%mod;
		} else {
			ans2 = (ans2*fac[p[i]])%mod;
			ans2 = (ans2*fac[p[i]])%mod;
		}
	}
	printf("%lld %lld\n", ans1, ans2);
}