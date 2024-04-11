#include<cstdio>
#include<algorithm>
using namespace std;

long long ra[21]={0},rb[21]={0};
int a[1048576],b[1048576];
int e2[21];
bool vis[21]={0};
void cntres(int x,int l,int r){
	if(x==0)return;
	int m=(l+r)>>1;
	for(int i=0;i<e2[x-1];i++)b[i]=a[i+m];
	sort(b,b+e2[x-1]);
	for(int i=l;i<m;i++)
		ra[x]+=lower_bound(b,b+e2[x-1],a[i])-b;
	cntres(x-1,l,m);
	cntres(x-1,m,r);
	return;
}
void cnt2(int x,int l,int r){
	if(x==0)return;
	int m=(l+r)>>1;
	for(int i=0;i<e2[x-1];i++)b[i]=a[i+m];
	sort(b,b+e2[x-1]);
	for(int i=l;i<m;i++)
		rb[x]+=e2[x-1]-(upper_bound(b,b+e2[x-1],a[i])-lower_bound(b,b+e2[x-1],a[i]));
	cnt2(x-1,l,m);
	cnt2(x-1,m,r);
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	e2[0]=1;
	for(int i=1;i<=n;i++)e2[i]=2*e2[i-1];
	int p=e2[n];
	for(int i=0;i<p;i++)scanf("%d",&a[i]);
	cntres(n,0,p);cnt2(n,0,p);
	for(int i=1;i<=n;i++)rb[i]+=rb[i-1];
//	for(int i=0;i<=n;i++)printf("%d\n",ra[i]);
	int m;scanf("%d",&m);
	for(int i=0;i<m;i++){
		int q;
		scanf("%d",&q);
		vis[q]=!vis[q];
		long long ans=0;
		for(int i=0;i<=n;i++){
			ans+=ra[i];
			if(vis[i])
				ans=rb[i]-ans;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}