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
	int size = 500000;
	vector<Mod> fac{Mod(1)};
	for(i=0; i<size; i++) {
		fac.push_back(fac.back()*(i+1));
	}
	auto comb_mod = [&](int n, int r) {
		Mod answer(fac[n]);
		answer /= fac[n-r];
		answer /= fac[r];
		return answer;
	};
	scanf("%d", &n);
	int a[n+1];
	for(i=0; i<=n; i++) {
		scanf("%d", &a[i]);
	}
	Mod answer(0);
	for(i=0; i<=n; i++) {
		if(a[i] != 0) {
			answer += comb_mod(i+a[i], a[i]-1);
		}
	}
	printf("%lld\n", answer.val);
}