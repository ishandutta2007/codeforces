#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int pow_mod(int a, int k) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

int inv_mod(int a) {
	return pow_mod(a, mod-2);
}

int comb_mod(int n, int r) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i))%mod;
	}
	return answer;
}

class Mod {
	public:
		long long val;
		
		Mod() {
			this->val = 0;
		}
		Mod(long long val) {
			this->val = val%mod;
		}
		Mod(long long num, long long den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		void operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		Mod operator+(int a) {
			return Mod((val+a)%mod);
		}
		void operator+=(int a) {
			val = (val+a)%mod;
		}
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		void operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		Mod operator-(int a) {
			return Mod((mod+val-a)%mod);
		}
		void operator-=(int a) {
			val = (mod+val-a)%mod;
		}
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		void operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		Mod operator*(int a) {
			return Mod((val*a)%mod);
		}
		void operator*=(int a) {
			val = (val*a)%mod;
		}
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		void operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
		Mod operator/(int a) {
			return Mod((val*inv_mod(a))%mod);
		}
		void operator/=(int a) {
			val = (val*inv_mod(a))%mod;
		}
};

int main() {
	int cl, ql;
	long long i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> t;
	for(cl=0; cl<t; cl++) {
		cin >> n;
		vector<multiset<int>> fac(n+1);
		for(i=2; i<=n; i++) {
			if(fac[i].empty()) {
				for(j=i; j<=n; j*=i) {
					for(k=j; k<=n; k+=j) {
						fac[k].insert(i);
					}
				}
			}
		}
		vector<map<int, vector<int>>> a(n);
		int x, y;
		for(i=0; i<n-1; i++) {
			cin >> u >> v >> x >> y;
			u--, v--;
			a[u][v] = {x, y};
			a[v][u] = {y, x};
		}
		vector<int> num(n+1, 0);
		vector<int> lcm(n+1, 0);
		vector<Mod> fin(n+1);
		fin[0] = Mod(1);
		int visited[n] = {};
		visited[0] = 1;
		function<void(int)> dfs = [&](int node) {
			for(auto it=a[node].begin(); it!=a[node].end(); it++) {
				int con = it->first;
				vector<int> r = it->second;
				if(!visited[con]) {
					visited[con] = 1;
					fin[con] = fin[node]*r[1]/r[0];
					set<int> check;
					for(auto d:fac[r[0]]) {
						num[d]--;
						check.insert(d);
					}
					for(auto d:fac[r[1]]) {
						num[d]++;
					}
					for(auto d:check) {
						lcm[d] = min(lcm[d], num[d]);
					}
					dfs(con);
					for(auto d:fac[r[0]]) {
						num[d]++;
					}
					for(auto d:fac[r[1]]) {
						num[d]--;
					}
				}
			}
		};
		dfs(0);
		Mod total(1);
		for(i=2; i<=n; i++) {
			for(j=0; j<(-lcm[i]); j++) {
				total *= i;
			}
		}
		Mod answer(0);
		for(i=0; i<n; i++) {
			answer += fin[i];
		}
		answer *= total;
		cout << answer.val << endl;
	}
}