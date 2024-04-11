#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
 
inline ull R(){
	ull ret=0;
	For(i,1,6) ret=(ret<<15)^rand();
	return ret;
}
 
const int N = 2e5+10, M = 65, maxn = 1<<15|10;
int n,m,p[M],f[maxn];
char s[N][M];
 
int main(){
    srand(time(0));
	n=read(),m=read(),read();
	For(i,1,n) scanf("%s",s[i]);
	int ans=0;
	ull Ans=0;
	For(T,1,20){
		int x=R()%n+1,cnt=0;
		FOR(j,0,m) if (s[x][j]=='1') p[++cnt]=j;
		FOR(i,0,1<<cnt) f[i]=0;
		For(i,1,n){
			int x=0;
			For(j,1,cnt) if (s[i][p[j]]=='1') x|=(1<<j-1);
			++f[x];
		}
		FOR(i,0,cnt) FOR(j,0,1<<cnt) if (!(j>>i&1)) f[j]+=f[j^(1<<i)];
		FOR(i,0,1<<cnt) if (f[i]>=(n+1)/2&&__builtin_popcount(i)>ans){
			ans=__builtin_popcount(i),Ans=0;
			For(j,1,cnt) if (i>>(j-1)&1) Ans|=1ll<<p[j];
		}
	}
	FOR(i,0,m) printf("%d",Ans>>i&1);
}