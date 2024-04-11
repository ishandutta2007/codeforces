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

const int N = 2e5+10;
int n,a[N],pos,cnt[N];

int pre[N<<1];
inline int calc(int x){
	For(i,0,2*n) pre[i]=-1; 
	pre[n]=0;
	int s=0,ans=0;
	For(i,1,n){
		if (a[i]==pos) ++s;
		if (a[i]==x) --s;
		if (pre[s+n]==-1) pre[s+n]=i;
			else ans=max(ans,i-pre[s+n]); 
	}
	return ans;
}

int main(){
	n=read();
	For(i,1,n) a[i]=read(),cnt[a[i]]++;
	int mx=0,tot=0;
	For(i,1,n){
		if (cnt[i]>mx) mx=cnt[i],pos=i,tot=1;
		else if (cnt[i]==mx) ++tot;
	}
	if (tot>1) return printf("%d\n",n),0;
	int ans=0;
	For(i,1,n) if (cnt[i]&&i!=pos) ans=max(ans,calc(i));
	printf("%d\n",ans);
}