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
int n,w,a[N],ans;
inline void solve(){
	n=read(),w=read();
	For(i,1,n) a[i]=read();
	multiset<int>s;
	s.insert(w),ans=1;
	sort(a+1,a+1+n);
	Dow(i,n,1){
		if (*s.rbegin()<a[i]){
			++ans,s.insert(w-a[i]);
			continue;
		}
		int tmp=*s.lower_bound(a[i]);
		s.erase(s.find(tmp)),s.insert(tmp-a[i]);
	}
	printf("%d\n",ans);
}

int main(){
	int T=read();
	while (T--) solve();
}