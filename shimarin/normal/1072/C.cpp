#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

int a,b;

inline bool check(int x){
	int A=a,B=b;
	Dow(i,x,1){
		if (A>B){
			if (A<i) return 0;
			A-=i;
		} else {
			if (B<i) return 0;
			B-=i;
		}
	}
	return 1;
}

int main(){
	a=read(),b=read();
	int l=1,r=100000,ans=0;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
	}
	int A=a,B=b;
	poly ans1,ans2;
	Dow(i,ans,1){
		if (A>B){
			A-=i,ans1.pb(i);
		} else {
			B-=i,ans2.pb(i);
		}
	}
	printf("%d\n",ans1.size());
	for (auto i:ans1) printf("%d ",i);puts("");
	printf("%d\n",ans2.size());
	for (auto i:ans2) printf("%d ",i);puts("");
}