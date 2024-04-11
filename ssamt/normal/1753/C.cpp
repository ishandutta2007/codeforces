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

vector<Mod> fac{Mod(1)};
Mod comb_mod(int n, int r) {
	for(int i=fac.size(); i<=n; i++) {
		fac.push_back(fac.back()*Mod(i));
	}
	return fac[n]/fac[r]/fac[n-r];
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	int x;
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int count = 0;
		for(i=0; i<n; i++) {
			count += a[i];
		}
		int diff = 0;
		for(i=0; i<n-count; i++) {
			diff += a[i];
		}
		Mod answer(0);
		for(i=diff; i>=1; i--) {
			answer += Mod(1)/(Mod(i)*i/n/(n-1)*2);
		}
		printf("%lld\n", answer.val);
	}
}