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

const int N = 410, mod = 998244353;
int n,m,a[35];

inline int Mod(int x){
	return x>=mod?x-mod:x;
}

int f0[N][26][26];
inline int solve0(){
	For(i,0,25) For(j,0,25) f0[2][i][j]=1;
	FOR(i,2,n) For(j,0,25) For(k,0,25) For(l,0,25) if (l!=j) f0[i+1][k][l]=Mod(f0[i+1][k][l]+f0[i][j][k]);
	int ans=0;
	For(i,0,25) For(j,0,25) ans=Mod(ans+f0[n][i][j]);
	return ans;
}

int f1[N][N][2][2];
inline int solve1(){
	For(i,0,1) For(j,0,1) f1[2][(i==1)+(j==1)][i][j]=(i==1?1:25)*(j==1?1:25);
	auto calc=[](int a,int b){
		if (b==0) return a==0?24:25;
		return 1;
	};
	FOR(i,2,n) For(c,0,i) For(j,0,1) For(k,0,1) if (f1[i][c][j][k]){
		For(l,0,1){
			if (l&&j) continue;
			f1[i+1][c+(l==1)][k][l]=(f1[i+1][c+(l==1)][k][l]+1ll*f1[i][c][j][k]*calc(j,l))%mod;
		}
	}
	int ans=0;
	For(i,0,25){
		For(j,a[i]+1,m) For(k,0,1) For(l,0,1) ans=Mod(ans+f1[n][j][k][l]); 
	}
	return ans;
}

int f[N][N][3][3],g[N][N][3][3],h[N][N];
inline int solve2(){
	For(i,0,2) For(j,0,2) f[(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i==0?24:1)*(j==0?24:1);
	auto calc=[](int a,int b){
		if (b==0) return a==0?23:24;
		return 1;
	};
	FOR(i,2,n){
		For(c1,0,i) For(c2,0,i-c1) For(j,0,2) For(k,0,2) if (f[c1][c2][j][k]){
			For(l,0,2){
				if (l&&j&&l==j) continue;
				int &x=g[c1+(l==1)][c2+(l==2)][k][l];
				x=(x+1ll*f[c1][c2][j][k]*calc(j,l))%mod;
			}
		}
		For(c1,0,i+1) For(c2,0,i+1-c1) For(j,0,2) For(k,0,2) f[c1][c2][j][k]=g[c1][c2][j][k],g[c1][c2][j][k]=0;
	}
	int ans=0;
	For(i,0,(n+1)/2) For(j,0,(n+1)/2) For(k,0,2) For(l,0,2) h[i][j]=Mod(h[i][j]+f[i][j][k][l]); 
	For(i,0,25) For(_i,i+1,25){
		For(j,a[i]+1,m) For(_j,a[_i]+1,m) ans=Mod(ans+h[j][_j]); 
	}
	return ans;
}

int main(){
	n=read();
	For(i,0,25) a[i]=read();
	m+=(n/2+1)/2;
	m+=((n+1)/2+1)/2;
	int ans=solve0();
	ans=Mod(ans+mod-solve1());
	ans=Mod(ans+solve2());
	printf("%d\n",ans);
}