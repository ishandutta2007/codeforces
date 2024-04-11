#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
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

const int N = 2e5+10;
int n,a[N],f[N];
inline void solve(){
	n=read();
	int s=0;
	For(i,1,n) a[i]=read(),s+=a[i];
	if (s<0){
		For(i,1,n) a[i]=-a[i];
		s=-s;
	}
	if (s%2) return puts("-1"),void(0);
	For(i,1,n) f[i]=0;
	int i=2;
	while (i<=n){
		if (a[i]>0&&s) f[i]=1,i+=2,s-=2;
			else ++i;
	}
	if (s) return puts("-1"),void(0);
	i=1;
	vector<pa>ans;
	while (i<=n){
		int j=i;
		if (j+1<=n&&f[j+1]){
			++j;
			while (j+2<=n&&f[j+2]) j+=2;
			ans.ep(i,j);
			i=j+1; 
		} else {
			ans.ep(i,i);
			++i;
		}
	}
	printf("%d\n",siz(ans));
	for (auto i:ans) printf("%d %d\n",i.fi,i.se);
}

int main(){
	int T=read();
	while (T--) solve();
}
/*
1
7
-1 1 0 1 0 1 0
*/