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

const int NN = 1000111;
int dp[NN][2];
int arr[NN];
int mm;

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	dp[1][1] = 1;
	dp[2][0] = 1;
	arr[mm++] = 1;
	arr[mm++] = 2;
	for(int n=4; n<NN; n++) {
		int m=1;
		int now = n;
		while(now>0) now-=m, m<<=1;
		m>>=1;
		now+=m;
		m>>=1;
		int st, ed;
		if(now<=m) st=0, ed=now;
		else st=now-m, ed=m;
		int c=0;
		int nn=1;
		while(nn<m) c+=nn, nn<<=1;
		for(int u=0; u<mm; u++) {
			int i = arr[u];
			if(i<c+st or i>c+ed) continue;
			if((i&1) and dp[i][1] and dp[n-i-1][0]) {
				dp[n][0] = 1;
			}
			if((i%2==0) and dp[i][0] and dp[n-i-1][0]) {
				dp[n][1] = 1;
			}
		}
		if(dp[n][0] + dp[n][1]) {
			arr[mm++] = n;
		}
	}
	int n;
	cin>>n;
	for(int i=0; i<mm; i++) if(arr[i] == n) return puts("1");
	cout << 0 << endl;
	return 0;
}