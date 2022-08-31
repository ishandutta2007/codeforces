#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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

const int N = 510;
int n,m,a[N][N],b[N][N],p[1000010];
bool vis[16];

int main(){
	n=read(),m=read();
	For(i,1,31) p[i*i*i*i]=1;
	int l=1;
	For(i,1,n) For(j,1,m){
		a[i][j]=read();
		int k=(i+j)&1;
		l=l*a[i][j]/__gcd(l,a[i][j]);
	}
	For(i,1,n){
		For(j,1,m) printf("%d ",(i+j&1)?l:l+a[i][j]*a[i][j]*a[i][j]*a[i][j]);
		puts("");
	}
}