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

int n,k;
char s[10];
inline int Query(int x,int y){
	if (x==n) return 1;
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='T';
}

inline void Ans(int x,int y){
	printf("2 %d %d\n",x,y);
	fflush(stdout);
}

inline int Find(int l,int r){
	if (l>r) return 0;
	int ret=-1;
	while (l<=r){
		int mid=l+r>>1;
		if (Query(mid,mid+1)==0) ret=mid,l=mid+1;
			else r=mid-1;
	}
	return ret+1;
}

int main(){
	n=read(),k=read();
	if (n==2) return Ans(1,2),0;
	int x=Query(1,2)==1?1:Find(1,n-1);
	int y=Find(1,x-1);
	if (y&&y!=x) return Ans(x,y),0;
	{
		y=Find(x+1,n);
		if (y&&y!=x) Ans(x,y);
			else Ans(x,x+1);
	}
}