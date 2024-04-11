#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxm=100000;
struct Node{
	int a,b;
	friend bool operator <(Node a,Node b){
		return a.b>b.b;
	}
}a[Maxm+5];
int b[Maxm+5];
bool cmp(int p,int q){
	return p>q;
}
ll sum[Maxm+5];
int n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a[i].a,&a[i].b);
			b[i]=a[i].a;
		}
		sort(a+1,a+1+m);
		sort(b+1,b+1+m,cmp);
		for(int i=1;i<=m;i++){
			sum[i]=sum[i-1]+b[i];
		}
		ll ans=0;
		for(int i=1,j=0;i<=m;i++){
			while(j<m&&b[j+1]>=a[i].b){
				j++;
			}
			if(j>=n){
				if(a[i].a>=b[n]){
					ans=max(ans,sum[n]);
				}
				else{
					ans=max(ans,sum[n-1]+a[i].a);
				}
			}
			else{
				if(j>0&&a[i].a>=b[j]){
					ans=max(ans,sum[j]+1ll*(n-j)*a[i].b);
				}
				else{
					ans=max(ans,sum[j]+a[i].a+1ll*(n-j-1)*a[i].b);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}