#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp_vector(const vector<int>& a, const vector<int>& b) {
	int i;
	for(i=0; i<a.size(); i++) {
		if(a[i] > b[i]) {
			return false;
		} else if(a[i] < b[i]) {
			return true;
		}
	}
	return false;
}

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

int main() {
	int h, i, j;
	int n, m, k;
	long long mod = 998244353;
	scanf("%d %d %d", &n, &m, &k);
	int x[k];
	int y[k];
	int t[k];
	int prev[k];
	for(i=0; i<k; i++) {
		prev[i] = -1;
	}
	int xvote[m][2] = {};
	int xmul[3] = {0,0,m};
	int yvote[n][2] = {};
	int ymul[3] = {0,0,n};
	int all[2] = {};
	int allmul[3] = {0,0,1};
	vector<vector<int> > a;
	for(i=0; i<k; i++) {
		scanf("%d %d %d", &x[i], &y[i], &t[i]);
		x[i]--;
		y[i]--;
		vector<int> e{x[i], y[i], i, t[i]};
		a.push_back(e);
	}
	sort(a.begin(), a.end(), cmp_vector);
	for(i=0; i<k-1; i++) {
		if(a[i][0] == a[i+1][0] && a[i][1] == a[i+1][1]) {
			prev[a[i+1][2]] = a[i][3];
		}
	}
	for(i=0; i<k; i++) {
		if(xvote[y[i]][0] && xvote[y[i]][1]) {
			xmul[0]--;
		} else if(!xvote[y[i]][0] && !xvote[y[i]][1]) {
			xmul[2]--;
		} else {
			xmul[1]--;
		}
		if(yvote[x[i]][0] && yvote[x[i]][1]) {
			ymul[0]--;
		} else if(!yvote[x[i]][0] && !yvote[x[i]][1]) {
			ymul[2]--;
		} else {
			ymul[1]--;
		}
		if(all[0] && all[1]) {
			allmul[0]--;
		} else if(!all[0] && !all[1]) {
			allmul[2]--;
		} else {
			allmul[1]--;
		}
		if(t[i] != -1) {
			xvote[y[i]][(t[i]+x[i])%2]++;
			yvote[x[i]][(t[i]+y[i])%2]++;
			all[(t[i]+x[i]+y[i])%2]++;
		}
		if(prev[i] != -1) {
			xvote[y[i]][(prev[i]+x[i])%2]--;
			yvote[x[i]][(prev[i]+y[i])%2]--;
			all[(prev[i]+x[i]+y[i])%2]--;
		}
		if(xvote[y[i]][0] && xvote[y[i]][1]) {
			xmul[0]++;
		} else if(!xvote[y[i]][0] && !xvote[y[i]][1]) {
			xmul[2]++;
		} else {
			xmul[1]++;
		}
		if(yvote[x[i]][0] && yvote[x[i]][1]) {
			ymul[0]++;
		} else if(!yvote[x[i]][0] && !yvote[x[i]][1]) {
			ymul[2]++;
		} else {
			ymul[1]++;
		}
		if(all[0] && all[1]) {
			allmul[0]++;
		} else if(!all[0] && !all[1]) {
			allmul[2]++;
		} else {
			allmul[1]++;
		}
		/*for(j=0; j<m; j++) {
			printf("%d %d  ", xvote[j][0], xvote[j][1]);
		}
		printf("\n");
		for(j=0; j<n; j++) {
			printf("%d %d  ", yvote[j][0], yvote[j][1]);
		}
		printf("\n");
		printf("%d %d", all[0], all[1]);
		printf("\n");
		printf("%d %d %d\n", xmul[0], xmul[1], xmul[2]);
		printf("%d %d %d\n", ymul[0], ymul[1], ymul[2]);
		printf("%d %d %d\n", allmul[0], allmul[1], allmul[2]);*/
		long long answer = 0;
		if(!xmul[0]) {
			answer = (answer+pow_mod(2, xmul[2], mod))%mod;
		}
		if(!ymul[0]) {
			answer = (answer+pow_mod(2, ymul[2], mod))%mod;
		}
		if(!allmul[0]) {
			answer = (answer-pow_mod(2, allmul[2], mod)+mod)%mod;
		}
		printf("%lld\n", answer);
	}
}