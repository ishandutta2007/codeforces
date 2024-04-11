#include<bits/stdc++.h>

using namespace std;
vector<long long> v;
long long f[300005], a[300005], sz[300005][2], rr1[300005], rr2[300005], pre[300005];
int nn;
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, l;
	long long mx = 0ll;
	cin >> n;
	for(int i = 0; i < n ; i ++) cin >> a[i], mx = max(a[i], mx);
	long long s = 1;
	for(l = 1; s < mx; l ++) s *= 2;
	l --;
	int hd = 0, tl = 1;
	long long ans = 0ll, rlt = 0ll;
	for(int i = l; i ; i --){
		long long r1 = 0, r2 = 0;
		nn = 0;
		memset(f, 0, sizeof(f));
		memset(rr1, 0, sizeof(rr1));
		memset(sz, 0, sizeof(sz));
		
		for(int j = 0; j < n; j ++) {
			int ip = (i == l) ? 0 : lower_bound(v.begin(), v.end(), pre[j]) - v.begin();
			if(a[j] & (1 << (i - 1)))sz[ip][1] ++;
			else sz[ip][0] ++;
			if(a[j] & (1 << (i - 1))) rr1[ip] += f[ip];
			else f[ip] ++;
			if(a[j] & (1 << (i - 1))) pre[j] |= (1 << (i - 1));
		}
		v.clear();
		for(int j = 0; j < n ; j ++) v.push_back(pre[j]);
		sort(v.begin(), v.end());
		v.erase( unique(v.begin(), v.end()) , v.end());
		nn = v.size();
		for(int j = 0; j < nn; j ++) rr2[j] = 1ll * sz[j][0] * sz[j][1] - rr1[j], r1 += rr1[j], r2 += rr2[j];// , cerr << rr1[j ] << " " << sz[j][0] << " " << sz[j][1] << endl;
		if(r1 >= r2) {
			ans += r2;
		}
		else ans += r1, rlt |= (1 << (i - 1));
	}
	cout << ans << " " << rlt << endl;
	return 0;
}