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

const int N = 1e5+10;
int n,m,l[N],r[N];
char s[N];
inline void solve(){
	n=read(),m=read();
	scanf("%s",s+1);
	For(i,1,n) 
		if (s[i]=='1') l[i]=i;
			else l[i]=l[i-1];
	r[n+1]=0;
	Dow(i,n,1)
		if (s[i]=='1') r[i]=i;
			else r[i]=r[i+1];
	For(i,1,n){
		if (s[i]=='1') putchar('1');
		else {
			int L=l[i]?i-l[i]:1e9,R=r[i]?r[i]-i:1e9;
			if (L==R) putchar('0');
			else if (min(L,R)<=m) putchar('1');
			else putchar('0');
		}
	}
	puts("");
}


int main(){
	int T=read();
	while (T--) solve();
}