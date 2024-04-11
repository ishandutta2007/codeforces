#include <cstdio>
#define Maxn 5000
bool is_p(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}
bool vis[Maxn+5];
int ans[Maxn+5][2],len;
int main(){
	int n;
	scanf("%d",&n);
	if(n==3){
		puts("3");
		puts("1 2");
		puts("2 3");
		puts("1 3");
		return 0;
	}
	if(n==4){
		puts("5");
		puts("1 2");
		puts("1 3");
		puts("2 3");
		puts("2 4");
		puts("3 4");
		return 0;
	}
	if(n==5){
		puts("5");
		puts("1 2");
		puts("2 3");
		puts("3 4");
		puts("4 5");
		puts("1 5");
		return 0;
	}
	if(n==7){
		puts("7");
		puts("1 2");
		puts("2 3");
		puts("3 4");
		puts("4 5");
		puts("5 6");
		puts("6 7");
		puts("1 7");
		return 0;
	}
	for(int i=1;i<n;i++){
		len++;
		ans[len][0]=i;
		ans[len][1]=i+1;
	}
	len++;
	ans[len][0]=1;
	ans[len][1]=n;
	int p;
	for(p=n;!is_p(p);p++);
	for(int i=1,j=1;i<=p-n;i++){
		while(vis[j]){
			j++;
		}
		len++;
		ans[len][0]=j;
		ans[len][1]=j+2;
		vis[j]=vis[j+2]=1;
	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d\n",ans[i][0],ans[i][1]);
	}
	puts("");
	return 0;
}