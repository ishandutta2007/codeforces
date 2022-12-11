#include<bits/stdc++.h>
using namespace std;
const int maxn=2222;
typedef long long LL;
LL a[maxn],b[maxn],p;
int n,m;

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%I64d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	long long ans=1LL<<61;
	for(int i=1;i+n-1<=m;i++){
		LL res=0;
		for(int j=1;j<=n;j++){
			res=max(res,llabs(a[j]-b[i+j-1])+llabs(b[i+j-1]-p));
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}