#include<bits/stdc++.h>



#define x first

#define y second

#define pb push_back



using namespace std;



typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pair;



template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}

template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}



int power(int a, int b, int m, int ans=1) {

	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;

	return ans;

}

#define NN 11111

#define MM 111



int cnt[MM];

int dp[2][MM][NN];



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in", "r", stdin);

	freopen("out.out", "w", stdout);

#endif

	int n;

	gn(n);

	

	for(int i=1; i<=n; i++) {

		int x; cin >> x;

		cnt[x]++;

	}

	

	int fl=0;

	dp[0][0][0] = 1;

	for(int t=1; t<=100; t++) if(cnt[t]){

		fl^=1;

		memset(dp[fl], 0, sizeof(dp[fl]));

		for(int i=n; i>=0; i--) for(int j=0; j<NN; j++) if(dp[fl^1][i][j]){

			for(int k=0; k<=cnt[t]; k++){

				int s=k*t;

				dp[fl][i+k][j+s]+=dp[fl^1][i][j];

				dp[fl][i+k][j+s]=min(dp[fl][i+k][j+s], 2);

			}

		}

	}

			

	int ans = 1;

	int ok=0;

	for(int t=1; t<=100; t++) if(cnt[t]) {

		for(int k=1; k<=cnt[t]; k++) if(dp[fl][k][k*t] == 1) ans = max(ans, k);

		ok++;

	}

	if(ok<=2) ans=n;

	

	cout<<ans<<endl;

}