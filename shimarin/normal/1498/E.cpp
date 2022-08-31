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

pa a[510];

int main(){
	int n=read();
	For(i,1,n) a[i]=mp(read(),i);
	sort(a+1,a+1+n);
	int s=0,l=1,x=0,y=0,ans=-1;
	For(i,1,n){
		s+=a[i].fi;
		if (s==i*(i-1)/2){
			For(j,l,i){
				For(k,j+1,i) if (a[k].fi-a[j].fi>ans) ans=a[k].fi-a[j].fi,x=a[j].se,y=a[k].se;
			}
			l=i+1;
		}
	}
	printf("! %d %d\n",x,y),fflush(stdout);
}