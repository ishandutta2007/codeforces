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

const int N = 1e5+10;
int n,a[N],b[N],pre[N][10];
bool f[N][10];

int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) b[i]=read();
	For(i,0,3) f[n][i]=1;
	Dow(i,n-1,1){
		For(j,0,3) For(k,0,3) if ((j|k)==a[i]&&(j&k)==b[i]){
			f[i][j]|=f[i+1][k],pre[i][j]=k;
		}
	}
	int ans=-1;
	For(i,0,3) if (f[1][i]){
		ans=i;
	}
	if (ans==-1) return puts("NO"),0;
	puts("YES");
	printf("%d ",ans);
	For(i,1,n-1) ans=pre[i][ans],printf("%d ",ans); 
}