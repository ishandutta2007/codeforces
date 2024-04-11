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

int a[200000];
inline void solve(){
	int n=read(),m=n;
	For(i,0,n-1) a[i]=i;
	while (n){
		int x=sqrt(n-1);
		if (x*x==n-1){
			reverse(a,a+n);
			break;
		}
		++x;
		int y=x*x-(n-1);
		reverse(a+y,a+n);
		n=y;
	}
	For(i,0,m-1) printf("%d ",a[i]);
	puts("");
}

int main(){
	int T=read();
	while (T--) solve();
}