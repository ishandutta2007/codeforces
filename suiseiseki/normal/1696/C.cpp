#include <cstdio>
typedef long long ll;
const int Maxn=50000;
int a[Maxn+5];
ll c[Maxn+5];
int b[Maxn+5];
ll d[Maxn+5];
int n,m,k;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=1;
		while(a[i]%m==0){
			a[i]/=m,c[i]*=m;
		}
	}
	for(int i=n-1;i>0;i--){
		if(a[i]==a[i+1]){
			c[i]+=c[i+1],c[i+1]=0;
		}
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&b[i]);
		d[i]=1;
		while(b[i]%m==0){
			b[i]/=m,d[i]*=m;
		}
	}
	for(int i=k-1;i>0;i--){
		if(b[i]==b[i+1]){
			d[i]+=d[i+1],d[i+1]=0;
		}
	}
	for(int i=1,j=1;i<=n||j<=k;i++,j++){
		while(i<=n&&c[i]==0){
			i++;
		}
		while(j<=k&&d[j]==0){
			j++;
		}
		if(i>n&&j>k){
			break;
		}
		if(i>n||j>k){
			puts("No");
			return;
		}
		if(a[i]==b[j]&&c[i]==d[j]){
			continue;
		}
		puts("No");
		return;
	}
	puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}