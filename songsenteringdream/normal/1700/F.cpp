#include<cstdio>
#include<cmath>
using namespace std;
const int o=2e5+10;
int n,a[2][o],b[2][o],s;long long ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<2;++i) for(int j=1;j<=n;++j) scanf("%d",&a[i][j]),s+=a[i][j];
	for(int i=0;i<2;++i) for(int j=1;j<=n;++j) scanf("%d",&b[i][j]),a[i][j]-=b[i][j],s-=b[i][j];
	if(s){printf("-1");return 0;}
	for(int i=0;i<2;++i) for(int j=1;j<=n;++j) a[i][j]+=a[i][j-1];
	for(int i=1,d=0;i<=n;++i){
		a[0][i]-=d;a[1][i]+=d;
		if(a[0][i]>0&&a[1][i]<0) --a[0][i],++a[1][i],++d,++ans;
		else if(a[0][i]<0&&a[1][i]>0) ++a[0][i],--a[1][i],--d,++ans;
		ans+=abs(a[0][i])+abs(a[1][i]);
	}
	printf("%lld",ans);
	return 0;
}