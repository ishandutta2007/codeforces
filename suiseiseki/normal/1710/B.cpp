#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,m;
struct Node{
	int x,p,id;
}a[Maxn+5];
int d_x[Maxn+5];
ll sum[Maxn+5];
ll max_r[Maxn+5],max_l[Maxn+5];
ll d_l[2][Maxn+5],d_r[2][Maxn+5];
bool ans[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].p);
		a[i].id=i;
		d_x[i]=a[i].x;
	}
	std::sort(d_x+1,d_x+1+n);
	for(int i=0;i<=n+1;i++){
		d_l[0][i]=d_l[1][i]=d_r[0][i]=d_r[1][i]=0;
		sum[i]=0;
		ans[i]=0;
	}
	std::sort(a+1,a+1+n,[](Node a,Node b){return a.x<b.x;});
	for(int i=1;i<=n;i++){
		d_l[1][i+1]+=a[i].p,d_l[1][i+1]+=a[i].x,d_l[0][i+1]--;
		int id=std::upper_bound(d_x+1,d_x+1+n,a[i].x+a[i].p)-d_x;
		d_l[1][id]-=a[i].p,d_l[1][id]-=a[i].x,d_l[0][id]++;
		d_r[1][i-1]+=a[i].p,d_r[1][i-1]-=a[i].x,d_r[0][i-1]++;
		id=std::lower_bound(d_x+1,d_x+1+n,a[i].x-a[i].p)-d_x;
		id--;
		d_r[1][id]-=a[i].p,d_r[1][id]+=a[i].x,d_r[0][id]--;
		sum[i]+=a[i].p;
	}
	for(int i=1;i<=n+1;i++){
		d_l[0][i]+=d_l[0][i-1],d_l[1][i]+=d_l[1][i-1];
	}
	for(int i=n;i>=0;i--){
		d_r[0][i]+=d_r[0][i+1],d_r[1][i]+=d_r[1][i+1];
	}
	for(int i=1;i<=n;i++){
		sum[i]+=1ll*(d_l[0][i]+d_r[0][i])*a[i].x+d_l[1][i]+d_r[1][i];
		if(sum[i]-m<=0){
			max_l[i]=max_r[i]=-Inf_ll;
		}
		else{
			max_l[i]=max_r[i]=std::max(0ll,sum[i]-m);
		}
	}
	for(int i=2;i<=n;i++){
		max_l[i]=std::max(max_l[i],max_l[i-1]+(a[i].x-a[i-1].x));
	}
	for(int i=n-1;i>0;i--){
		max_r[i]=std::max(max_r[i],max_r[i+1]+(a[i+1].x-a[i].x));
	}
	for(int i=1;i<=n;i++){
		if(a[i].p>=max_l[i]&&a[i].p>=max_r[i]){
			ans[a[i].id]=1;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}