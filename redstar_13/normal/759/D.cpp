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

#define NN 5050
const int mod=1000000007;
char s[NN];
char t[NN];
int pre[NN];
int dp[2][NN];

inline void add(int &a, int b){
	a+=b;
	if(a>=mod) a-=mod;
	if(a<0) a+=mod;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, m;
	
	cin >> n;
	scanf("%s", s+1);
	strcpy(t+1, s+1);
	
	t[(m=unique(t+1, t+n+1)-t-1)+1]=0;
	
	int last[26]={0, };
	for(int i=1; i<=m; i++) pre[i]=last[t[i]-'a'], last[t[i]-'a']=i;
	
	int f=0;
	
	for(int i=1; i<=n; i++){
		f^=1;
		for(int j=0; j<=m; j++) dp[f][j]=0;
		for(int j=1; j<=m; j++){
			if(i==1) add(dp[f][j], pre[j]==0);
			else add(dp[f][j], dp[f^1][j]-dp[f^1][pre[j]]);
			add(dp[f][j], dp[f][j-1]);
		}
	}
	
	cout << dp[f][m] << endl;
	
	return 0;
}