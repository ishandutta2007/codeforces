#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
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

const int N = 1010;
int n,k,c[N][N];

int main(){
	n=read(),k=read();
	int ans=1,now=k;
	while (233){
		for (int i=1;i<=n;i+=now)
			for (int j=i;j<=min(n,i+now-1);++j)
				for (int k=j+1;k<=min(n,i+now-1);++k) if (!c[j][k]) c[j][k]=ans;
		if (now>=n) break;
		now*=k,++ans;
	}
	printf("%d\n",ans);
	For(i,1,n) For(j,i+1,n) printf("%d ",c[i][j]);
}