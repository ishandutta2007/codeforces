#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp pake_pair
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucksm
#define y1 fucklzw
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=1e5+5,MOD=1e9+7;
const ld eps=1e-12;
int l[N],r[N],n;
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d%d",l+i,r+i);
	sort(l+1,l+n+1);sort(r+1,r+n+1);
	ll ans=0;
	rep(i,n)ans+=max(l[i],r[i]);
	printf("%lld\n",ans+n);
	return 0;
}