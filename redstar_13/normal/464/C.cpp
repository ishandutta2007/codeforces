#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 100010
#define mod 1000000007

int val[11], len[11];
string query[NN];
char res[NN];
int d[NN];
char s[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	scanf("%s", s);
	int n;
	gn(n);
	for(int i=1; i<=n; i++) {
		scanf("%1d->", d+i);
		gets(res);
		query[i] = res;
	}
	
	for(int i=0; i<=9; i++) len[i] = 1, val[i] = i;
	
	for(int i=n; i; i--) {
		int m = query[i].size();
		int Len = 0, sum = 0;
		for(int j=0; j<m; j++) {
			int x = query[i][j] - '0';
			sum = (INT) sum * power(10, len[x], mod) % mod + val[x];
			sum %= mod;
			Len += len[x];
			Len %= (mod - 1);
		}
		val[d[i]] = sum;
		len[d[i]] = Len;
	}
	
	int ans = 0;
	int m = strlen(s);
	
	for(int i=0; i<m; i++) {
		int x = s[i] - '0';
		ans = (INT) ans * power(10, len[x], mod) % mod + val[x];
		ans %= mod;
	}
	
	cout<<ans<<endl;
}