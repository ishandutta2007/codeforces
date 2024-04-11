#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=300000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int lst[Maxn+5],pos[Maxn+5];
int len[Maxn+5],ans[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			lst[i]=pos[i]=0;
			len[i]=0;
			ans[i]=Inf;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			lst[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			len[a[i]]=max(len[a[i]],i-lst[i]);
		}
		for(int i=1;i<=n;i++){
			if(pos[i]){
				len[i]=max(len[i],n+1-pos[i]);
			}
		}
		for(int i=1;i<=n;i++){
			if(len[i]){
				ans[len[i]]=min(ans[len[i]],i);
			}
		}
		for(int i=2;i<=n;i++){
			ans[i]=min(ans[i],ans[i-1]);
		}
		for(int i=1;i<=n;i++){
			if(ans[i]==Inf){
				printf("-1 ");
			}
			else{
				printf("%d ",ans[i]);
			}
		}
		puts("");
	}
	return 0;
}