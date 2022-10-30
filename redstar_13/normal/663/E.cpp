#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 100100
int a[NN];
char s[NN];
int dp[21][1<<20];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%s", s);
		for(int j=0; j<m; j++) a[j]=a[j]<<1|(s[j]=='1');
	}
	
	for(int i=0; i<m; i++) dp[0][a[i]]++;
	for(int i=1; i<=n; i++){
		for(int j=i; j>=1; j--) for(int k=1<<n; k--; ){
			dp[j][k]+=dp[j-1][k^(1<<i-1)];
		}
	}
	
	int ans=n*m;
	for(int k=1<<n; k--; ){
		int s=0;
		for(int j=0; j<=n; j++) s+=min(j, n-j)*dp[j][k];
		smin(ans, s);
	}
	
	cout << ans << endl;
	
	return 0;
}