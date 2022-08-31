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

const int N = 1<<20|10;
int n,m,a[N],b[N];
inline int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}
inline void solve(){
	n=read(),m=1<<n;
	For(i,1,m) a[i]=i;
	while (m>2){
		int cnt=0;
		for (int i=1;i<=m;i+=4){
			int t=query(a[i],a[i+2]);
			if (t==0){
				b[++cnt]=(query(a[i+1],a[i+3])==1?a[i+1]:a[i+3]);
			} else if (t==1){
				b[++cnt]=(query(a[i],a[i+3])==1?a[i]:a[i+3]);
			} else {
				b[++cnt]=(query(a[i+2],a[i+1])==1?a[i+2]:a[i+1]);
			}
		}
		m=cnt;
		For(i,1,m) a[i]=b[i];
	}
	if (m==2){
		if (query(a[1],a[2])==2) swap(a[1],a[2]);
	}
	printf("! %d\n",a[1]);
	fflush(stdout);
}

int main(){
	int T=read();
	while (T--) solve();
}