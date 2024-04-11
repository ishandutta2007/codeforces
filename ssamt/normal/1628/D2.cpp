#include <bits/stdc++.h>

using namespace std;

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

//p must be prime
int inv_mod(int a, int p) {
	return pow_mod(a, p-2, p);
}

//mod must be prime
int comb_mod(int n, int r, int mod) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r, mod);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i, mod))%mod;
	}
	return answer;
}

int mod = 1e9+7;
class Mod {
	public:
		long long val;
		
		Mod(int val) {
			this->val = val;
		}
		
		Mod(int num, int den) {
			this->val = ((long long)num*inv_mod(den, mod))%mod;
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
			return Mod((val*inv_mod(a.val, mod))%mod);
		}
		
		Mod operator/=(Mod a) {
			val = (val*inv_mod(a.val, mod))%mod;
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
		scanf("%d %d %d", &n, &m, &k);
		vector<Mod> comb;
		comb.push_back(Mod(1));
		for(i=m-1; i>=0; i--) {
			comb.push_back(comb.back()*(n-1-i)/(m-i));
		}
		Mod answer(0);
		for(i=1; i<=m; i++) {
			answer += comb[m-i]/pow_mod(2, n-i, mod)*i;
			//printf("%d ", comb[m-i]);
		}
		answer *= k;
		printf("%lld\n", answer.val);
	}
}