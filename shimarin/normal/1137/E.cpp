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
#define ll __int128
inline void Print(__int128 x){
	if (x>=10) Print(x/10);
	putchar('0'+x%10);
}

const int N = 3e5+10;
int top;
ll stk[N],sb,sx,x[N],b[N];

inline ll F(int u){
	return stk[u]*(sx-x[u])+sb-b[u];
}
inline void fix(){
	while (top>1){
		if (F(top)>=F(top-1)) --top;
			else break;
	}
}

int main(){
	ll n=read(),q=read();
	stk[top=1]=0;
	while (q--){
		int opt=read();
		if (opt==1){
			n+=read();
			stk[top=1]=0,x[1]=sx,b[1]=sb;
		}
		if (opt==2){
			while (top>1){
				ll k=(F(top-1)-F(top))/(stk[top]-stk[top-1]);
				if (F(top)+k*stk[top]>n*k) --top,fix();
					else break;
			}
			stk[++top]=n,n+=read(),x[top]=sx,b[top]=sb;
		}
		if (opt==3){
			ll b=read(),s=read();
			sb+=b,sx+=s;
		}
		fix();
		//printf("%lld %lld\n",stk[top]+1,F(top));
		Print(stk[top]+1),putchar(' '),Print(F(top)),putchar('\n');
	}
}