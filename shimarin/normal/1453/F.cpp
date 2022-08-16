/*
.....
.../.|
./ /|
.|.  |
 }F...
  . --.._
  > 
/ 
 p_.
r ` .
{^ 
__--  |
_= _
          

*/
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

const int N = 3010, inf = 1e9;
int n,a[N],f[N][N],pre[N],suf[N];
inline void solve(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) For(j,1,n) f[i][j]=inf;
	f[n][n]=0;
	Dow(i,n-1,1) if (i+a[i]==n){
		f[i][n]=0;
		FOR(j,i+1,n) f[i][n]+=(j+a[j]==n);
	}
	Dow(j,n-1,1){
		int cnt=0;
		suf[n+1]=inf;
		Dow(k,n,j+1) suf[k]=min(suf[k+1],f[j][k]);
		Dow(i,j-1,1){ 
			//For(k,j+1,n) if (i+a[i]>=j&&i+a[i]<k) f[i][j]=min(f[i][j],f[j][k]+cnt);
			if (i+a[i]>=j) f[i][j]=min(f[i][j],suf[i+a[i]+1]+cnt);
			cnt+=(i+a[i]>=j);
		}
	}
	int ans=inf;
	For(j,1,n) ans=min(ans,f[1][j]);
	printf("%d\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}