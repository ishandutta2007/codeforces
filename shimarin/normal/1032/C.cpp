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
int n,a[N],pre[N][6],ans[N];
bool f[N][6];

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	For(i,1,5) f[1][i]=1;
	For(i,2,n){
		if (a[i]==a[i-1]){
			For(j,1,5) if (f[i-1][j]){
				For(k,1,5) if (j!=k) f[i][k]=1,pre[i][k]=j;
			}
		} else if (a[i]>a[i-1]){
			For(j,1,5) if (f[i-1][j]){
				For(k,j+1,5) f[i][k]=1,pre[i][k]=j;
				break;
			}
		} else {
			Dow(j,5,1) if (f[i-1][j]){
				Dow(k,j-1,1) f[i][k]=1,pre[i][k]=j;
			}
		}
	}
	For(j,1,5) if (f[n][j]){
		ans[n]=j;
		int y=pre[n][j];
		Dow(i,n-1,1) ans[i]=y,y=pre[i][y];
		For(i,1,n) printf("%d ",ans[i]);
		puts("");
		return 0;
	}
	puts("-1");
}