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
int n,a[10000];
inline bool check(int x){
	for (int i=2;i*i<=x;++i) if (x%i==0) return 1;
	return 0;
}
inline void solve(){
	n=read();
	int s=0;
	For(i,1,n) a[i]=read(),s+=a[i];
	if (check(s)){
		printf("%d\n",n);
		For(i,1,n) printf("%d ",i);
		puts("");
	} else {
		For(i,1,n) if (check(s-a[i])){
			printf("%d\n",n-1);
			For(j,1,n) if (i!=j) printf("%d ",j);
			puts("");
			return;
		}
	}
}

int main(){
	int T=read();
	while (T--) solve();
}