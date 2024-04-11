#include <cstdio>
int a[105];
int n;
int ab(int a){
	return a<0?-a:a;
}
int work(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i]*(ab(x-i)+i-1+x-1);
		ans+=a[i]*(x-1+i-1+ab(x-i));
	}
	return ans;
}
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++){
		ans=mn(ans,work(i));
	}
	printf("%d\n",ans);
	return 0;
}