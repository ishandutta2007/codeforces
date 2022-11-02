#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

const int NN = 400011;
const int MM = 21;
int a[NN];
int c[MM];
INT gas[MM][MM];
INT dp[1<<MM];
int vst[MM];

#define bit(i, j) ((i>>j)&1)

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	cin >> n;
	INT ans = 0;
	
	for(int i=1; i<=n; i++) {
		scanf("%d", a+i);
		vst[a[i]] = 1;
	}
	int nn = 0;
	for(int i=1; i<=20; i++) if(vst[i] == 1) vst[i] = nn++;
	for(int i=1; i<=n; i++) {
		a[i] = vst[a[i]];
		c[a[i]]++, ans+=i;
		ans -= c[a[i]];
	}
	
	for(int j=0; j<nn; j++) {
		int c = 0;
		for(int i=1; i<=n; i++) {
			if(a[i] == j) c++;
			gas[j][a[i]] += c;
		}
	}
	dp[0] = 0;
	for(int i=1; i<1<<nn; i++) {
		dp[i] = -1;
		for(int j=0; j<nn; j++) if(bit(i, j)) {
			INT tmp = dp[i^(1<<j)];
			for(int k=0; k<nn; k++) if(bit(i, k) and k!=j) {
				tmp += gas[k][j];
			}
			if(tmp > dp[i]) dp[i] = tmp;
		}
	}
	ans -= dp[(1<<nn)-1];
	cout << ans << endl;
	return 0;
}