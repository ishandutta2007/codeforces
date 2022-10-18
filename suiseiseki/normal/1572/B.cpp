#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5];
int b[Maxn+5],len;
void solve(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum^=a[i];
	}
	if(sum==1){
		puts("NO");
		return;
	}
	len=0;
	if(a[1]==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				continue;
			}
			if(~(i-1)&1){
				for(int j=i-1;j>0;j-=2){
					b[++len]=j-1;
					a[j]=a[j-1]=0;
				}
				break;
			}
			if(i+1<=n&&a[i+1]==1){
				b[++len]=i-1;
				a[i-1]=a[i+1]=0;
				for(int j=i-2;j>0;j-=2){
					b[++len]=j-1;
					a[j]=a[j-1]=0;
				}
				break;
			}
			if(i+1<=n){
				b[++len]=i-1;
				a[i]=a[i+1]=1;
			}
			else{
				puts("NO");
				return;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i]==0){
			continue;
		}
		if(i+1>n){
			puts("NO");
			return;
		}
		if(a[i+1]==1){
			b[++len]=i-1;
			a[i]=a[i+1]=0;
			continue;
		}
		if(i+2>n){
			puts("NO");
			return;
		}
		if(a[i+2]==1){
			b[++len]=i;
			a[i]=a[i+2]=0;
			continue;
		}
		b[++len]=i;
		a[i+1]=a[i+2]=1;
		b[++len]=i-1;
		a[i]=a[i+1]=0;
	}
	puts("YES");
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d ",b[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}