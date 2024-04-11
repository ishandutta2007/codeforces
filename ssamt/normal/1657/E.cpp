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
	cin >> n >> k;
	n--;
	vector<Mod> fac{Mod(1)};
	for(i=1; i<=n; i++) {
		fac.push_back(fac.back()*i);
	}
	vector<vector<Mod>> comb(n+1, vector<Mod>(n+1));
	for(i=0; i<=n; i++) {
		for(j=0; j<=i; j++) {
			comb[i][j] = fac[i]/fac[j]/fac[i-j];
		}
	}
	vector<vector<Mod>> d(k+1, vector<Mod>(n+1));
	for(i=k; i>=1; i--) {
		for(j=0; j<=n; j++) {
			if(j <= 0) {
				d[i][j] = Mod(1);
			} else if(i == k) {
				d[i][j] = Mod(pow_mod(k, ((long long)j*(j-1)/2)%(mod-1)));
			} else {
				d[i][j] = Mod(0);
				for(l=0; l<=j; l++) {
					d[i][j] += comb[j][l]*pow_mod(i, ((long long)l*(l-1)/2+(long long)l*(j-l))%(mod-1))*d[i+1][j-l];
				}
			}
		}
	}
	cout << d[1][n].val << endl;
}