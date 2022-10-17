#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n;
int a[Maxn+5],id_tot;
int st[Maxn+5],top;
int maxn[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(n<<1);i++){
		char op[5];
		scanf("%s",op);
		if((*op)=='+'){
			st[++top]=++id_tot;
			maxn[top]=0;
		}
		else{
			int x;
			scanf("%d",&x);
			if(top==0){
				puts("NO");
				return 0;
			}
			if(x<maxn[top]){
				puts("NO");
				return 0;
			}
			a[st[top]]=x;
			maxn[top-1]=max(maxn[top-1],maxn[top]);
			top--;
			maxn[top]=max(maxn[top],x);
		}
	}
	if(top>0){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}