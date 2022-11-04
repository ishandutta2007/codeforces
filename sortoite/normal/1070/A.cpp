#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define inf 0x3f3f3f3f
#define NN 1010101

int d, s;
int dp[5050][505];
int f[NN]={1};

void calc(int S, int M, int N) {
	if(N==1) {printf("%d", S); return ;}
	for(int x=0; x<=min(S, 9); x++) if(N>=dp[S-x][((M-x*f[N-1]%d)+d)%d]+1) {
		int sum=S-x;
		printf("%d", x);
		calc(S-x, ((M-x*f[N-1]%d)+d)%d, N-1);
		return ;
	}
}

inline void solve(int x) {
	int sum=s-x;
	for(int i=0; i<d; i++) if(dp[s][0]>=dp[sum][i]+1) {
		int val=x*f[dp[s][0]-1] + i;
		if(val%d==0) {
			printf("%d", x);
			calc(sum, i, dp[s][0]-1);
			exit(0);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	scanf("%d %d", &d, &s);
	for(int i=1; i<NN; i++) f[i]=10*f[i-1]%d;
	
	for(int i=1; i<=s; i++) {
		for(int j=0; j<d; j++) {
			dp[i][j]=inf;
		}
	}
	
	queue<pii> q;
	for(int i=1; i<=9; i++) {
		dp[i][i%d]=1;
		q.push(pii(i, i%d));
	}
	while(!q.empty()) {
		int sum=q.front().x, mod=q.front().y; q.pop();
		for(int i=0; i<=9; i++) {
			int Sum=sum+i, Mod=(mod*10+i)%d;
			if(Sum<=s && dp[Sum][Mod]>dp[sum][mod]+1) {
				dp[Sum][Mod]=dp[sum][mod]+1;
				q.push(pii(Sum, Mod));
			}
		}
	}
	
	if(dp[s][0]==inf)  puts("-1");
	else if(dp[s][0]==1) printf("%d", s);
	else for(int i=1; i<=9; i++) solve(i);
}