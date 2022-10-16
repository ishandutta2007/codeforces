#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=300000;
int n;
int a[Maxn+5];
int get_val(int x){
	int ans=0;
	if(x<n-1){
		if(a[x+1]>a[x]&&a[x+1]>a[x+2]){
			ans++;
		}
		else if(a[x+1]<a[x]&&a[x+1]<a[x+2]){
			ans++;
		}
	}
	if(x>2){
		if(a[x-1]>a[x-2]&&a[x-1]>a[x]){
			ans++;
		}
		else if(a[x-1]<a[x-2]&&a[x-1]<a[x]){
			ans++;
		}
	}
	if(x!=1&&x!=n){
		if(a[x]<a[x-1]&&a[x]<a[x+1]){
			ans++;
		}
		else if(a[x]>a[x-1]&&a[x]>a[x+1]){
			ans++;
		}
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=2){
		puts("0");
		return;
	}
	int ans=0;
	for(int i=2;i<n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			ans++;
		}
		else if(a[i]<a[i-1]&&a[i]<a[i+1]){
			ans++;
		}
	}
	int all=ans;
	for(int i=1;i<=n;i++){
		int tmp=a[i];
		int now=all;
		now-=get_val(i);
		a[i]=a[i+1];
		now+=get_val(i);
		ans=min(ans,now);
		now-=get_val(i);
		a[i]=a[i-1];
		now+=get_val(i);
		ans=min(ans,now);
		a[i]=tmp;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}