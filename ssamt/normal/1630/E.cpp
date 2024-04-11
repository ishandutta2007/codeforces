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

long long gcd(long long num1, long long num2)//greatest common divisor
{
	if(num1<0)
		return gcd(-num1, num2);
	if(num2<0)
		return gcd(num1, -num2);
	if(num1 == 0)
		return num2;
	if(num2 == 0)
		return num1;
	while(num1%num2!=0 && num2%num1!=0)
	{
		if(num1>num2)
			num1 %= num2;
		else
			num2 %= num1;
	}
	return (num1<num2)?num1:num2;
}

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int same = 1;
		for(i=1; i<n; i++) {
			if(a[i] != a[0]) {
				same = 0;
			}
		}
		if(same) {
			printf("1\n");
		} else {
			int count[n+1] = {};
			for(i=0; i<n; i++) {
				count[a[i]]++;
			}
			vector<int> c;
			int g = 0;
			for(i=1; i<=n; i++) {
				if(count[i] != 0) {
					c.push_back(count[i]);
					g = gcd(count[i], g);
				}
			}
			long long mul[g+1] = {};
			long long d[g+1];
			for(i=1; i<=g; i++) {
				if(g%i == 0) {
					d[i] = i-mul[i];
					for(j=i; j<=g; j+=i) {
						mul[j] += d[i];
					}
				}
			}
			vector<Mod> fac{Mod(1)};
			for(i=1; i<=n; i++) {
				fac.push_back(fac.back()*i);
			}
			Mod num(0);
			Mod den(0);
			for(i=1; i<=g; i++) {
				if(g%i == 0) {
					Mod coef(0);
					coef += Mod(n/i)*Mod(n/i);
					for(j=0; j<c.size(); j++) {
						coef -= Mod(c[j]/i)*Mod(c[j]/i);
					}
					//printf("%lld\n", coef.val);
					coef /= Mod(n/i)*Mod(n/i-1);
					coef *= Mod(n);
					Mod add = fac[n/i];
					for(j=0; j<c.size(); j++) {
						add *= fac[c[j]];
						add /= fac[c[j]/i];
					}
					add *= Mod(d[i]);
					num += add*coef;
					den += add;
					//printf("%lld %lld %lld %lld\n", add.val, coef.val, num.val, den.val);
				}
			}
			printf("%lld\n", (num/den).val);
		}
	}
}