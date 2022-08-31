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

const int N = 1010, mod = 998244353;
int n,m,f[N][N][2];
char s[N],t[N];

inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	For(i,1,m){
		f[0][i][1]=1;
		if (t[i]!=t[i-1]) f[0][i][1]+=f[0][i-1][1];
	}
	For(i,1,n){
		f[i][0][0]=1;
		if (s[i]!=s[i-1]) f[i][0][0]+=f[i-1][0][0];
	}
	For(i,1,n){
		For(j,1,m){
			if (s[i]!=t[j]){
				f[i][j][1]+=f[i][0][0];
				f[i][j][0]+=f[0][j][1];
			}
		}
	}
	int ans=0;
	For(i,1,n) For(j,1,m){
		if (i+1<=n){
			if (s[i]!=s[i+1]) upd(f[i+1][j][0],f[i][j][0]);
			if (s[i+1]!=t[j]) upd(f[i+1][j][0],f[i][j][1]);
		}
		if (j+1<=m){
			if (t[j]!=t[j+1]) upd(f[i][j+1][1],f[i][j][1]);
			if (s[i]!=t[j+1]) upd(f[i][j+1][1],f[i][j][0]);
		}
		upd(ans,f[i][j][0]),upd(ans,f[i][j][1]);
	}
	printf("%d\n",ans);
}