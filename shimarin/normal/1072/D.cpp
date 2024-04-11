#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

const int N = 2010;
int n,k,flag[N][N];
char s[N][N];

int f[N][N],mx,x,y;
inline void Get1(){
	f[1][1]=(s[1][1]!='a');
	For(i,1,n){
		For(j,1,n){
			if (i==1&&j==1) continue;
			f[i][j]=1e9;
			if (i>1)
				if (f[i-1][j]+(s[i][j]!='a')<f[i][j]) f[i][j]=f[i-1][j]+(s[i][j]!='a');
			if (j>1)
				if (f[i][j-1]+(s[i][j]!='a')<f[i][j]) f[i][j]=f[i][j-1]+(s[i][j]!='a');
		}
	}
	x=1,y=0,mx=1;
	For(i,1,n) For(j,1,n) if (f[i][j]<=k){
		if (i+j>mx) mx=i+j,x=i,y=j;
	}
}

bool Flag;
inline void print(int i,int j){
	int x=0;
	if (flag[i-1][j]) x=1,print(i-1,j);
	else if (flag[i][j-1]) x=1,print(i,j-1);
	if (x||Flag) printf("%c",s[i][j]);
}

int main(){
	n=read(),k=read();
	For(i,1,n) scanf("%s",s[i]+1);
	Get1();
	if (mx==n*2){
		For(i,1,n*2-1) putchar('a');
		return 0;
	}
	For(i,1,mx-1) putchar('a');
	if (mx==1){
		Flag=1,mx=2,x=1,y=1,flag[1][1]=1;
	}
	For(i,1,n){
		int j=mx-i;
		if (j>=1&&j<=n){
			if (f[i][j]<=k) flag[i][j]=1;
		}
	}
	For(i,1,n-x+n-y){
		int mn=1e9;
		++mx;
		For(j,1,n){
			int k=mx-j;
			if (k>=1&&k<=n){
				if (flag[j-1][k]||flag[j][k-1]) mn=min(mn,(int)s[j][k]);
			}
		}
		For(j,1,n){
			int k=mx-j;
			if (k>=1&&k<=n){
				if (s[j][k]!=mn) continue;
				if (flag[j-1][k]||flag[j][k-1]) flag[j][k]=1;
			}
		}
	}
	print(n,n);
}