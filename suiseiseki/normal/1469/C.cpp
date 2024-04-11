#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=200000;
int n,k;
int h[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&h[i]);
		}
		int left=h[1],right=h[1];
		bool flag=1;
		for(int i=2;i<=n;i++){
			left=max(h[i],left-k+1);
			right=min(h[i]+k-1,right+k-1);
			if(left>right||left-h[i]>=k){
				flag=0;
				break;
			}
		}
		if(flag&&left==h[n]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}