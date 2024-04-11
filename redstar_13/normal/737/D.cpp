#include<bits/stdc++.h>

#define x first
#define y second

#define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

#define NN 4010
#define MM 90

INT dp[NN][MM][MM];
INT a[NN];
INT sum[NN];
int n;

INT solve(int st, int ma, int delta);

INT calc(int st, int ed, int ma, int delta) {
	if(st + ma > ed) return 0;
	INT s = inf;
	s = min(s, solve(st, ma, delta) - (sum[ed] - sum[ed-ma]));
	if(st + ma + 1 < ed) s = min(s, solve(st, ma+1, delta+1) - (sum[ed] - sum[ed-ma-1]));
	return s;
}

INT solve(int st, int ma, int delta) {
	if(dp[st][ma][delta] != -inf) return dp[st][ma][delta];
	
	int ed = n - st - delta;
	if(st + ma > ed) return dp[st][ma][delta] = 0;
	INT s = -inf;
	
	s = max(s, sum[st+ma] - sum[st] + calc(st+ma, ed, ma, delta));
	if(st + ma + 1 <= ed) s = max(s, sum[st+ma+1] - sum[st] + calc(st+ma+1, ed, ma+1, delta));
	return dp[st][ma][delta] = s;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	gn(n);
	sum[0] = 0;
	for(int i=1; i<=n; i++) gn(a[i]), sum[i] = sum[i-1] + a[i];
	sum[n+1] = sum[n];
	
	for(int i=0; i<NN; i++) for(int j=0; j<MM; j++) 
		for(int k=0; k<MM; k++) dp[i][j][k] = -inf;
	
	cout<<solve(0, 1, 0)<<endl;
	
}