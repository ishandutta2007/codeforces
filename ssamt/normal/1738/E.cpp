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
	return fac[n]/fac[r]/fac[n-r];
}

int main() {
	int i, j, k, l;
	int t, n, m, q;
	for(int i=1; i<=1e5; i++) {
		fac.push_back(fac.back()*Mod(i));
	}
	scanf("%d", &t);
	for(int cl=0; cl<t; cl++) {
		scanf("%d", &n);
		vector<int> a(n);
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int l = -1, r = n;
		long long lsum = 0, rsum = 0;
		vector<vector<int>> z;
		while(l < r) {
			if(lsum < rsum) {
				l++;
				lsum += a[l];
			} else if(lsum > rsum) {
				r--;
				rsum += a[r];
			} else {
				for(i=l+1; i<r && a[i]==0; i++);
				for(j=r-1; j>l && a[j]==0; j--);
				if(i > j) {
					z.push_back({i-j-1});
				} else {
					z.push_back({i-l-1, r-j-1});
				}
				l = i;
				lsum += a[i];
				r = j;
				rsum += a[j];
			}
		}
		/*for(i=0; i<z.size(); i++) {
			for(j=0; j<z[i].size(); j++) {
				printf("%d ", z[i][j]);
			}
			printf("\n");
		}*/
		Mod answer(1);
		if(z.size() == 1 && z[0].size() == 1) {
			answer = Mod(pow_mod(2, z[0][0]-1));
		} else {
			for(i=0; i<z.size() && z[i].size() == 2; i++) {
				Mod mul(0);
				if(i == 0) {
					for(j=0; j<=min(z[i][0], z[i][1]); j++) {
						mul += comb_mod(z[i][0], j)*comb_mod(z[i][1], j);
					}
				} else {
					for(j=0; j<=min(z[i][0], z[i][1])+1; j++) {
						mul += comb_mod(z[i][0]+1, j)*comb_mod(z[i][1]+1, j);
					}
				}
				answer *= mul;
			}
			if(z.back().size() == 1) {
				answer *= pow_mod(2, z.back()[0]+1);
			}
		}
		printf("%lld\n", answer.val);
	}
}