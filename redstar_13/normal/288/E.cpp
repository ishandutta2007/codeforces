#include<bits/stdc++.h>



using namespace std;



typedef long long INT;



#define NN 100010

#define mod 1000000007



INT p[10][NN];

INT sum[3][NN];



int pre() {

	p[0][0] = p[2][0] = 1;

	for(int i=1; i<NN; i++) {

		p[4][i] = ((INT) p[4][i-1] * 10 + 4) % mod;

		p[7][i] = ((INT) p[7][i-1] * 10 + 7) % mod;

		p[0][i] = (INT) p[0][i-1] * 10 % mod;

		p[2][i] = (INT) p[2][i-1] * 2 % mod;

	}

	sum[1][1] = 11, sum[2][1] = 28;

	for(int i=2; i<NN; i++) {

		sum[1][i] = (sum[1][i-1] * 2 + (p[2][i] - 1) * 11 % mod * 

			p[0][i-1] % mod + p[7][i-1] + p[4][i-1]) % mod;

		INT md4 = p[0][i-1] * 4 % mod, md7 = p[0][i-1] * 7 % mod;

		sum[2][i] = (sum[2][i-1] * 2 + sum[1][i-1] * (md4 + md7) % mod) % mod;

		sum[2][i] = (sum[2][i] + (md4 * md4 % mod + md7 * md7 % mod) * (p[2][i-1] - 1)

			% mod + (md4 + p[7][i-1]) * (md7+p[4][i-1]) % mod) % mod;

	}

}



INT calc(char * s) {

	int n = strlen(s);

	INT ans = 0, md = 0;

	for(int i=0; i<n; i++) {

		md = (INT) md * 10 % mod;

		if(s[i] == '7') {

			int len  = n - i - 1;

			INT tmp = (INT) (md + 4) * p[0][len] % mod;

			ans = (ans + tmp * tmp % mod * (p[2][len] - 1) % mod) % mod;

			ans = (ans + tmp * sum[1][len] % mod) % mod;

			ans = (ans + sum[2][len]) % mod;

			ans = (ans + ((INT) (md+7) * p[0][len] + p[4][len]) % mod * ((INT) (md + 4) * 

				p[0][len] % mod + p[7][len]) % mod) % mod;

		}

		md = (md + s[i] - '0') % mod;

	}

	return ans;

}



char s[NN];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in","r",stdin);

	freopen("out.out","w",stdout);

#endif

	pre();

	INT ans = 0;

	scanf("%s", s);

	ans = -calc(s);

	scanf("%s", s);

	ans += calc(s);

	ans = (ans % mod + mod) % mod;

	

	cout << ans << endl;

	return 0;

}