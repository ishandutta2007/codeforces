#include <cstdio>
#define Maxn 100000
#define Maxm 300
int a[Maxn+5];
struct Segment{
	int left,right;
}seg[Maxm+5];
int mx(int a,int b){
	return a>b?a:b;
}
int now[Maxn+5];
int an[Maxn+5];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&seg[i].left,&seg[i].right);
	}
	int tmp;
	int ans=0,ans_len=0;
	int len;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			tmp=0;
			len=0;
			for(int k=1;k<=m;k++){
				if((seg[k].left<=i&&i<=seg[k].right)&&(seg[k].left>j||seg[k].right<j)){
					tmp++;
					now[++len]=k;
				}
			}
			if(a[j]-a[i]+tmp>ans){
				ans=a[j]-a[i]+tmp;
				ans_len=len;
				for(int k=1;k<=len;k++){
					an[k]=now[k];
				}
			}
		}
	}
	printf("%d\n%d\n",ans,ans_len);
	for(int i=1;i<=ans_len;i++){
		printf("%d ",an[i]);
	}
	puts("");
	return 0;
}