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

const int N = 1e3+10;
int n,m,a[N][N],pos1[N][N],pos2[N][N],s[N],S[N];
pa b[N];

int main(){
	n=read(),m=read();
	For(i,1,n) For(j,1,m) a[i][j]=read();
	For(i,1,n){
		For(j,1,m) b[j]=mp(a[i][j],j);
		sort(b+1,b+1+m);
		int cnt=0;
		For(j,1,m){
			if (b[j].fi!=b[j-1].fi) ++cnt;
			pos1[i][b[j].se]=cnt;
		}
		s[i]=cnt;
	}
	For(j,1,m){
		For(i,1,n) b[i]=mp(a[i][j],i);
		sort(b+1,b+1+n);
		int cnt=0;
		For(i,1,n){
			if (b[i].fi!=b[i-1].fi) ++cnt;
			pos2[b[i].se][j]=cnt;
		}
		S[j]=cnt;
	}
	For(i,1,n){
		For(j,1,m){
			int k=max(pos1[i][j],pos2[i][j]);
			printf("%d ",k+max(s[i]-pos1[i][j],S[j]-pos2[i][j]));
		}
		puts("");
	}
}