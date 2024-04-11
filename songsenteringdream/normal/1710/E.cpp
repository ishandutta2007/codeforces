#include<cstdio>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int n,m,a[o],b[o],a1,b1,ans;long long s[o],mx,t;
inline bool chk(int md){
	if(a[a1]+b[b1]<=md) return true;
	bool res=mx=0;
	for(int i=1,j=m;i<=n;s[i]=s[i-1]+j,++i) for(;j&&a[i]+b[j]>md;--j);
	for(int i=m,j=n,k=0;i;--i){
		for(;j&&s[j]-s[j-1]+i<m;--j);
		if(mx<(t=s[j]-(m-i)*1ll*j-i*1ll*(n-k)+s[n]-s[k])) mx=t,res=0;
		if(mx==t) res|=(b1<=i||a1<=j);
		for(;k<n&&s[k+1]-s[k]==i;++k);
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	a1=a[1];b1=b[1];
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	for(int i=1;i<=n;++i) if(a[i]==a1){a1=i;break;}
	for(int i=1;i<=m;++i) if(b[i]==b1){b1=i;break;}
	for(int l=1,r=1e9,md;l<r;ans=l) if(chk(md=l+r>>1)) r=md;else l=md+1;
	printf("%d",ans);
	return 0;
}