#include <cstdio>
const int Maxn=(1<<16);
int n;
bool vis[Maxn+5];
int b[Maxn+5];
int a[Maxn+5];
int id[Maxn+5];
int query_and(int x,int y){
	printf("AND %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int query_or(int x,int y){
	printf("OR %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int query_xor(int x,int y){
	printf("XOR %d %d\n",x,y);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		a[i]=query_xor(1,i);
	}
	for(int i=2;i<=n;i++){
		if(a[i]==0){
			vis[1]=vis[i]=1;
			b[1]=b[i]=query_and(1,i);
			break;
		}
		if(id[a[i]]>0){
			b[id[a[i]]]=b[i]=query_and(id[a[i]],i);
			vis[id[a[i]]]=vis[i]=1;
			b[1]=b[i]^a[i];
			vis[1]=1;
			break;
		}
		id[a[i]]=i;
	}
	if(!vis[1]){
		for(int i=2;i<=n;i++){
			if(a[i]==(n>>1)-1){
				b[1]|=query_and(1,i);
			}
			if(a[i]==(n>>1)){
				b[1]|=query_and(1,i);
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(vis[i]){
			continue;
		}
		b[i]=(b[1]^a[i]);
	}
	printf("! ");
	for(int i=1;i<=n;i++){
		printf("%d ",b[i]);
	}
	puts("");
	fflush(stdout);
	return 0;
}