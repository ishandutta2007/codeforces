#include <cstdio>
#define Maxn 300000
int a[Maxn+5];
int f[20][Maxn+5];
int n;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
void init(){
	for(int i=1;i<=(n<<1)+n;i++){
		f[0][i]=a[i];
	}
	for(int i=1;(1<<i)<=(n<<1)+n;i++){
		for(int j=1;j+(1<<i)-1<=(n<<1)+n;j++){
			f[i][j]=mx(f[i-1][j],f[i-1][j+(1<<(i-1))]);
		}
	}
}
int find(int x){
	int left=0,right=19,mid;
	while(left<right){
		mid=(left+right+1)>>1;
		if((1<<mid)<=x){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	return left;
}
int query(int left,int right){
	if(left>n){
		return 0;
	}
	if(left>right){
		return 0;
	}
	int len=right-left+1;
	int k=find(len);
	return mx(f[k][left],f[k][right-(1<<k)+1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
		a[i+n+n]=a[i];
	}
	init();
	int maxn,minn;
	maxn=a[1],minn=a[1];
	for(int i=2;i<=n;i++){
		if(maxn<a[i]){
			maxn=a[i];
		}
		if(minn>a[i]){
			minn=a[i];
		}
	}
	if((minn<<1)>=maxn){
		for(int i=1;i<=n;i++){
			printf("-1 ");
		}
		puts("");
		return 0;
	}
	int pos=1;
	maxn=a[1];
	for(int i=1;i<=n;i++){
		while((a[pos]<<1)>=maxn){
			maxn=mx(maxn,a[pos]);
			pos++;
		}
		printf("%d ",pos-i);
		maxn=query(i+1,pos);
	}
	puts("");
	return 0;
}