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
	int size = 200000;
	Mod d[size+1];
	d[0] = d[1] = Mod(1);
	for(i=2; i<=size; i++) {
		d[i] = d[i-1]+d[i-2];
	}
	for(i=1; i<=size; i++) {
		d[i] += d[i-1];
	}
	int p;
	scanf("%d %d", &n, &p);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	Mod answer = 0;
	for(i=0; i<n; i++) {
		int val = a[i];
		int find = 0;
		while(val > 0) {
			if(val%4 == 0) {
				val /= 4;
			} else if(val%2 == 1) {
				val /= 2;
			} else {
				break;
			}
			if(binary_search(a, a+n, val)) {
				find = 1;
				break;
			}
		}
		if(!find) {
			for(j=0; a[i]>>j; j++);
			if(p-j >= 0) {
				answer += d[p-j];
			}
		}
	}
	printf("%d\n", answer);
}