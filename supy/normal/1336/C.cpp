#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 3333,mo=998244353;
int n,m;char s[N],t[N];
int f[N][N],g[N][N];
void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int main() {
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);s[n+1]='.';m=strlen(t+1);
	rep(i,1,m)f[i][i-1]=1;//
	per(l,m+1,1)rep(r,l-1,m){
	//	printf("%d %d:%d\n",l,r,f[l][r]);
	if(r<m){
		if(t[r+1]==s[r-l+1+1])add(f[l][r+1],f[l][r]);
		if(t[l-1]==s[r-l+1+1])add(f[l-1][r],f[l][r]);
	}
	else{
		add(g[r-l+1][l],f[l][r]);f[l][r]=0;
		/*printf("%d %d:%d\n",r-l+1,);
		add(g[r-l+2][l],g[r-l+1][l]);
		if(t[l-1]==s[r-l+2])add(g[r-l+2][l-1],g[r-l+1][l]);*/
	}
	}
	rep(i,0,n-1)per(l,m,1)if(g[i][l]){
	//	printf("%d %d:%d\n",i,l,g[i][l]);
		add(g[i+1][l],g[i][l]);
		if(t[l-1]==s[i+1])add(g[i+1][l-1],g[i][l]);
	}
	int res=0;rep(i,1,n)add(res,g[i][1]);
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	reverse(t+1,t+m+1);
	static int nxt[N],trs[N][27];
	for(int i=2,j=0;i<=m;i++){
		while(j&&t[i]!=t[j+1])j=nxt[j];
		if(t[i]==t[j+1])j++;
		nxt[i]=j;
	}
	rep(i,0,m)rep(c,0,25){
		int j=i;
		while(j&&c+'a'!=t[j+1])j=nxt[j];
		if('a'+c==t[j+1])j++;
		trs[i][c]=j;
	}
	f[0][0]=1;
	rep(i,0,n-1)rep(j,0,m){
		add(f[i+1][j],f[i][j]);
		add(f[i+1][trs[j][s[i+1]-'a']],f[i][j]);
	}
	rep(i,0,n)add(res,f[i][m]);
	cout<<res;
	return 0;
}