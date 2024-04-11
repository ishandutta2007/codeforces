#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=300000;
int n;
int a[Maxn+5];
int f_1[(Maxn>>1)+5],f_2[(Maxn>>1)+5];
int ans[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[1]=max(ans[1],a[i]);
	}
	for(int i=1;i<n;i++){
		f_1[min(i,n-i)]=max(f_1[min(i,n-i)],max(a[i],a[i+1]));
	}
    for(int i=2;i<n;i++){
		f_2[min(i-1,n-i)]=max(f_2[min(i-1,n-i)],max(min(a[i-1],a[i]),min(a[i],a[i+1])));
	}
    for(int i=(n>>1);i>0;i--){
		ans[i<<1]=max(ans[(i+1)<<1],f_1[i]);
		ans[i<<1|1]=max(ans[(i+1)<<1|1],f_2[i]);
	}
	for(int i=n;i>0;i--){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}