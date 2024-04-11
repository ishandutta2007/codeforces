#include <cstdio>
#include <algorithm>
const int Maxn=200;
int n;
int p[Maxn+5];
int query_1(int x,int y){
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int query_2(int x,int id){
	printf("2 %d %d ",x,n-id);
	for(int i=id;i<n;i++){
		printf("%d ",p[i]);
	}
	puts("");
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
bool cmp(int x,int y){
	return query_1(y,x);
}
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p[i]=i;
	}
	std::sort(p,p+n,cmp);
	static int g[Maxn+5];
	int len=0;
	for(int i=0,j=0,lst=0;i<n;i++){
		while(j+1<n&&query_2(p[i],j+1)){
			j++;
		}
		if(i==j){
			len++;
			for(int k=lst;k<=j;k++){
				g[p[k]]=len;
			}
			j++;
			lst=j;
		}
	}
	puts("3");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d",(g[i]>=g[j]));
		}
		puts("");
	}
	fflush(stdout);
	int x;
	scanf("%d",&x);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}