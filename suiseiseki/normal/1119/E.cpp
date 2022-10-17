#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 300000
int a[Maxn+5];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll ans=0;
	ll las=0;
	ll now;
	for(int i=1;i<=n;i++){
		now=min((ll)a[i]>>1,las);
		ans+=now;
		las-=now;
		a[i]-=(now<<1);
		ans+=a[i]/3;
		a[i]%=3;
		las+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}