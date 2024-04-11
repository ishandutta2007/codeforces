#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
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

const int N = 31;
int n,m,a[N];

inline int Query(int x){
	printf("%d\n",x),fflush(stdout);
	int ans=read();
	if (ans==0) exit(0);
	return ans;
}

int main(){
	m=read(),n=read();
	For(i,1,n){
		int tmp=Query(1);
		if (tmp==1) a[i]=0;
			else a[i]=1;
	}
	int l=1,r=m,cnt=0;
	while (l<=r){
		int mid=l+r>>1;
		++cnt;
		int tmp=Query(mid);
		if (a[(cnt-1)%n+1]){
			if (tmp==1) r=mid-1;
				else l=mid+1;
		} else {
			if (tmp==1) l=mid+1;
				else r=mid-1;
		}
	}
}