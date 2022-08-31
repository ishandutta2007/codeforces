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

const int N = 110;
int n;
char s[N];
inline void solve(){
	scanf("%s",s+1),n=strlen(s+1);
	int p1=0,p2=0;
	Dow(i,n,1) if (s[i]=='1'&&s[i+1]=='1') p1=i;
	For(i,1,n) if (s[i]=='0'&&s[i+1]=='0') p2=i;
	if (!p1||!p2) return puts("YES"),void(0);
	puts(p1>p2?"YES":"NO");
}

int main(){
	int T=read();
	while (T--) solve();
}