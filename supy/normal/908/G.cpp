#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 707, mo = 1e9+7;
char s[N];int n,f[N][N][2],res;
void add(int &x, ll y){x=(x+y)%mo;}
int main() {
	scanf("%s",s+1);n=strlen(s+1);reverse(s+1,s+n+1);
	rep(c,1,9){
		memset(f,0,sizeof(f));f[n+1][0][0]=1;
		per(i,n+1,1)rep(j,0,n+1-i)rep(k,0,1)if(f[i][j][k]){
			if(k)add(f[i-1][j+1][k],1LL*f[i][j][k]*(10-c)),add(f[i-1][j][k],1LL*f[i][j][k]*c);
			else rep(v,0,s[i-1]-'0') add(f[i-1][j+(v>=c)][k|(v<s[i-1]-'0')],f[i][j][k]);
		}
		int mi=1,now=0;
		rep(i,1,n){
			add(now,mi);mi=10LL*mi%mo;add(res,1LL*now*(f[1][i][0]+f[1][i][1]));
		}
	}
	cout<<res;
	return 0;
}