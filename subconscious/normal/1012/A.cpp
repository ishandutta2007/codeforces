#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5;
int a[N],n,mi=2e9;
int main(){
	scanf("%d",&n);
	rep(i,n<<1)scanf("%d",a+i);
	sort(a+1,a+n*2+1);
	for(int i=2;i<=n;++i)mi=min(mi,a[i+n-1]-a[i]);
	ll ans=1ll*(a[n]-a[1])*(a[n*2]-a[n+1]);
	ans=min(ans,1ll*mi*(a[2*n]-a[1]));
	printf("%lld\n",ans);
	//system("pause");
	//rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}