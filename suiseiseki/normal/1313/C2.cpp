#include <cmath>
#include <cstdio>
int mn(int a,int b){
	return a<b?a:b;
}
const int Maxn=500000;
typedef long long ll;
int a[Maxn+5];
ll f[Maxn+5],g[Maxn+5];
int n;
int minn[20][Maxn+5];
int b[Maxn+5];
void init(){
	for(int i=1;i<=n;i++){
		minn[0][i]=a[i];
	}
	for(int i=1;(1<<i)<=n;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			minn[i][j]=mn(minn[i-1][j],minn[i-1][j+(1<<(i-1))]);
		}
	}
}
int query(int l,int r){
	int k=(int)log2(r-l+1);
	return mn(minn[k][l],minn[k][r-(1<<k)+1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	int left,right,mid;
	for(int i=1;i<=n;i++){
		if(a[i]>=a[i-1]){
			f[i]=f[i-1]+a[i];
		}
		else{
			left=1,right=i-1;
			while(left<right){
				mid=(left+right)>>1;
				if(query(mid,i-1)>a[i]){
					right=mid;
				}
				else{
					left=mid+1;
				}
			}
			f[i]=f[left-1]+1ll*(i-left+1)*a[i];
		}
	}
	for(int i=n;i>0;i--){
		if(a[i]>=a[i+1]){
			g[i]=g[i+1]+a[i];
		}
		else{
			left=i+1,right=n;
			while(left<right){
				mid=(left+right+1)>>1;
				if(query(i+1,mid)>a[i]){
					left=mid;
				}
				else{
					right=mid-1;
				}
			}
			g[i]=g[left+1]+1ll*(left-i+1)*a[i];
		}
	}
	int pos=0;
	ll maxn=0;
	for(int i=1;i<=n;i++){
		if(f[i]+g[i]-a[i]>maxn){
			maxn=f[i]+g[i]-a[i];
			pos=i;
		}
	}
	b[pos]=a[pos];
	for(int i=pos-1;i>0;i--){
		b[i]=mn(b[i+1],a[i]);
	}
	for(int i=pos+1;i<=n;i++){
		b[i]=mn(b[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	return 0;
}