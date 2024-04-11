#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define x0 fuckyzc
#define y0 fuckcjb
#define x1 fuckjtjl
#define y1 fucksf
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,P=1e9+7,inf=0x3f3f3f3f;
const ld eps=1e-9;
int a[N],n,s;ll ans;
int main(){
	scanf("%d%d",&n,&s);
	rep(i,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	ans=0;
	rep(i,n/2){
		if(a[i]>s)ans+=a[i]-s;
		if(a[n-i+1]<s)ans+=s-a[n-i+1];
	}
	ans+=abs(a[n/2+1]-s);
	printf("%lld\n",ans);
	return 0;
}