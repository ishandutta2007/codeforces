#include <cstdio>
#include <cassert>
const int Maxn=1000;
int n;
int a[Maxn+5];
int lis[Maxn+5],len;
int sum;
int val,ans;
void make_op(){
	int tmp=val;
	printf("%d ",val);
	while(tmp>0){
		tmp--;
		a[lis[len]]=1;
		sum++;
		printf("%d ",lis[len]+1);
		len--;
	}
	puts("");
}
int main(){
	scanf("%d",&n);
	if(n<=3){
		puts("0");
		return 0;
	}
	for(int i=2;i<=n;i++){
		int tmp=n-(i+1)-(n-(i+1))/i;
		if(tmp>ans){
			ans=tmp;
			val=i;
		}
	}
	for(int i=0;i<n;i++){
		if(i%val){
			lis[++len]=i;
		}
	}
	while(sum<ans){
		make_op();
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==-1){
			return 0;
		}
		x--;
		int tmp=val;
		for(int i=x;tmp>0;i=(i+1)%n,tmp--){
			if(a[i]){
				lis[++len]=i;
				sum-=a[i];
				a[i]=0;
			}
		}
	}
	puts("0");
	return 0;
}