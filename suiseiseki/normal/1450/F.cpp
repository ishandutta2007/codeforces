#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n;
int a[Maxn+5];
int num[Maxn+5],cnt[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num[i]=cnt[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if((num[i]<<1)>n+1){
			puts("-1");
			return;
		}
	}
	int ans=1;
	cnt[a[1]]++;
	cnt[a[n]]++;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			ans++;
			cnt[a[i]]+=2;
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,cnt[i]);
	}
	if(maxn<=ans+1){
		printf("%d\n",ans-1);
	}
	else{
		int id=0;
		for(int i=1;i<=n;i++){
			if(maxn==cnt[i]){
				id=i;
				break;
			}
		}
		int sum=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=id&&a[i-1]!=id){
				sum++;
			}
		}
		while(sum--){
			ans++;
			if(maxn<=ans+1){
				printf("%d\n",ans-1);
				break;
			}
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}