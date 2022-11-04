#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007
multiset<int> q[200005];
map<int, int> ID;
typedef pair<int, int> pii;
map<pii, int> nn;
int np;
typedef long long LL;
LL modExp(LL a, LL n, int m) {
	LL r;
	a = (a % m + m) % m;
	for (r = 1; n; n /= 2) {
		if (n & 1) r = r * a % m;
		a = a * a % m;
	}
	return r;
}
int get_id(int u) {
	if(ID.count(u)) return ID[u];
	return ID[u] = np ++;
}
int main(){
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n, qq, a;
	cin >> n >> qq;
	for(int i = 0; i < n ; i ++) {
		cin >> a;
		int aa = a;
		for(int j = 2; j * j <= a; j ++) if(aa % j == 0) {
			int cnt = 0;
			while(aa % j == 0) cnt ++, aa /= j;;
			nn[pii(i, j)] = cnt;
			q[j].insert(cnt);
		}
		if(aa > 1){
			nn[pii(i, aa)] = 1;
			q[aa].insert(1);
		}
	}
	int id, x;
	long long rlt = 1;
	for(int i = 2; i <= 200000; i ++) if(q[i].size() == n) rlt = rlt * modExp(i, *q[i].begin(), mod) % mod;
	for(int i = 0; i < qq; i ++) {
		cin >> id >> x;
		id --;
		int aa = x;
		for(int j = 2; j * j <= x; j ++) if(aa % j == 0) {
			int cnt = 0;
			while(aa % j == 0) cnt ++, aa /= j;
			if(nn.count(pii(id, j))) {
				int ko = 0;
				if(q[j].size() == n) ko = *q[j].begin();
				q[j].erase(q[j].lower_bound(nn[pii(id, j)]));
				nn[pii(id, j)] += cnt;
				q[j].insert(nn[pii(id, j)]);
				if(q[j].size() == n) rlt = rlt * modExp(j, *q[j].begin() - ko, mod) % mod;
			}
			else {
				nn[pii(id, j)] = cnt;
				q[j].insert(nn[pii(id, j)]);
				if(q[j].size() == n) rlt = rlt * modExp(j, *q[j].begin(), mod) % mod;
			}
		}
		if(aa > 1){
			if(nn.count(pii(id, aa))) {
				int ko  = 0;
				if(q[aa].size() == n) ko = *q[aa].begin();
				q[aa].erase(q[aa].lower_bound(nn[pii(id, aa)]));
				nn[pii(id, aa)] += 1;
				q[aa].insert(nn[pii(id, aa)]);
				if(q[aa].size() == n) rlt = rlt * modExp(aa, *q[aa].begin()- ko, mod) % mod;
			}
			else {
				nn[pii(id, aa)] = 1;
				q[aa].insert(nn[pii(id, aa)]);
				if(q[aa].size() == n) rlt = rlt * modExp(aa, *q[aa].begin(), mod) % mod;
			}
		}
		cout << rlt << endl;
	}
	return 0;
}