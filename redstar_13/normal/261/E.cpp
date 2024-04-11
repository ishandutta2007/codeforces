#include<bits/stdc++.h>



using namespace std;



typedef long long INT;



inline int is_prime(int u) {

	for(int i=2; i<u; i++) if(u % i == 0) return 0;

	return 1;

}



#define NN 3001000

#define inf 0x3f3f3f3f



int tot = 0;

int L, R, p;

int all[NN];

int flag[NN];

int dp[NN];



inline int update(int q) {

	int nn = tot;

	for(int i=0; i<nn; i++) {

		int val = all[i];

		while((INT) val * q <= R) {

			val *= q;

			all[tot++] = val;

		}

	}

}



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in","r",stdin);

	freopen("out.out","w",stdout);

#endif

	cin >> L >> R >> p;

	

	all[tot++] = 1;

	

	for(int i=2; i<=p; i++) if(is_prime(i))

		update(i);

	

	sort(all, all+tot);

	

	for(int i=0; i<NN; i++) dp[i] = inf;

	dp[0] = 0;

	flag[0] = 1;

	

	for(int i=2; i<=p; i++) {

		int pos = 0;

		for(int j=0; j<tot; j++) if(dp[j] != inf) {

			INT v = (INT) all[j] * i;

			while(pos < tot and all[pos] != v) pos++;

			if(pos == tot) break;

			dp[pos] = min(dp[pos], dp[j] + 1);

			if(dp[pos] + i <= p) flag[pos] = 1;

		}

	}

	

	int ans = 0;

	for(int i=0; i<tot; i++) if(flag[i] and all[i] >= L) ans++;

	

	cout << ans << endl;

}