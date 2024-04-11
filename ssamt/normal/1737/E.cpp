#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

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
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<Mod> answer(n, Mod(0));
		vector<Mod> sum(n+1, Mod(0));
		for(i=n-1; i>=0; i--) {
			answer[i] = Mod(1)/pow_mod(2, i/2+1);
			if(i == n-1) {
				answer[i] *= 2;
			}
			Mod mul(1);
			if(2*i+1 < n) {
				mul -= sum[2*i+1];
			}
			answer[i] *= mul;
			sum[i] = sum[i+1]+answer[i];
		}
		for(i=0; i<n; i++) {
			printf("%lld\n", answer[i].val);
		}
	}
}