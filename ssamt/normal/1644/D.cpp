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
		
		Mod(int val) {
			this->val = val;
		}
		
		Mod(int num, int den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		
		Mod operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		
		Mod operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		
		Mod operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		
		Mod operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d %d %d %d", &n, &m, &k, &q);
		int x[q], y[q];
		for(i=0; i<q; i++) {
			scanf("%d %d", &x[i], &y[i]);
			x[i]--, y[i]--;
		}
		map<int, int> cx, cy;
		for(i=0; i<q; i++) {
			cx[x[i]] = i;
			cy[y[i]] = i;
		}
		int check[q] = {};
		for(auto pair:cx) {
			check[pair.second] = 1;
		}
		for(auto pair:cy) {
			check[pair.second] = 1;
		}
		set<int> findx, findy;
		for(i=q-1; i>=0; i--) {
			if(findx.size() == n || findy.size() == m) {
				check[i] = 0;
			}
			findx.insert(x[i]);
			findy.insert(y[i]);
		}
		int count = 0;
		for(i=0; i<q; i++) {
			count += check[i];
		}
		Mod answer(1);
		for(i=0; i<count; i++) {
			answer *= k;
		}
		printf("%d\n", answer.val);
	}
}