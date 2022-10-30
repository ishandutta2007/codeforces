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

int mod = 1e9+7;
class ModFrac {
	public:
		long long val;
		
		ModFrac(int val) {
			this->val = val;
		}
		
		ModFrac(int num, int den) {
			this->val = ((long long)num*inv_mod(den, mod))%mod;
		}
		
		ModFrac operator+(ModFrac a) {
			return ModFrac((val+a.val)%mod);
		}
		
		ModFrac operator+=(ModFrac a) {
			val = (val+a.val)%mod;
		}
		
		ModFrac operator-(ModFrac a) {
			return ModFrac((mod+val-a.val)%mod);
		}
		
		ModFrac operator-=(ModFrac a) {
			val = (mod+val-a.val)%mod;
		}
		
		ModFrac operator*(ModFrac a) {
			return ModFrac((val*a.val)%mod);
		}
		
		ModFrac operator*=(ModFrac a) {
			val = (val*a.val)%mod;
		}
		
		ModFrac operator/(ModFrac a) {
			return ModFrac((val*inv_mod(a.val, mod))%mod);
		}
		
		ModFrac operator/=(ModFrac a) {
			val = (val*inv_mod(a.val, mod))%mod;
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	int mod = 1e9+7;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		int n[2], b[2], d[2];
		int p;
		scanf("%d %d %d %d %d %d %d", &n[0], &n[1], &b[0], &b[1], &d[0], &d[1], &p);
		vector<int> after;
		for(i=0; i<2; i++) {
			for(j=0; j<n[1-i]-1; j++) {
				if(b[i] <= d[i]) {
					after.push_back(d[i]-b[i]+2*j*(n[i]-1));
					after.push_back(2*n[i]-d[i]-b[i]+2*j*(n[i]-1));
				} else {
					after.push_back(2*n[i]-d[i]-b[i]+2*j*(n[i]-1));
					after.push_back(2*(n[i]-1)+d[i]-b[i]+2*j*(n[i]-1));
				}
			}
		}
		sort(after.begin(), after.end());
		/*for(i=0; i<after.size(); i++) {
			printf("%d ", after[i]);
		}
		printf("\n");*/
		int count = 0;
		ModFrac cycle(0);
		ModFrac prob(p, 100);
		for(i=0; i<after.size(); i++) {
			if((i == 0 || after[i-1] != after[i]) && after[i] < 2*(n[0]-1)*(n[1]-1)) {
				cycle += prob*ModFrac(after[i]);
				prob *= ModFrac(100-p, 100);
				//printf("%lld %lld\n", cycle.val, prob.val);
			}
		}
		prob *= ModFrac(100, p);
		//printf("%lld %lld\n", cycle.val, prob.val);
		ModFrac minus = ModFrac(1)-prob;
		ModFrac answer = (cycle+ModFrac(2*(n[0]-1)*(n[1]-1))*prob)/minus;
		printf("%lld\n", answer.val);
	}
}