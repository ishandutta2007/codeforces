#include <cstdio>
const int Maxn=100000;
int n,m;
int a[Maxn+5];
int r[Maxn+5];
double p[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int pos=n+1;
	while(pos-1>0&&a[pos-1]==pos-1){
		pos--;
	}
	double ans=1;
	if(pos==1){
		ans=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%lf",&r[i],&p[i]);
		if(r[i]>=pos-1){
			ans*=(1-p[i]);
		}
	}
	ans=1-ans;
	printf("%.9lf\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}