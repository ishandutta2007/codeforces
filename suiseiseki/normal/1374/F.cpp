#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=510;
int Q,n,top,b[N],a[N],c[N],ans[N*N],vis[N];
bool solve(){
	for(int k=1;k<=n-2;k++){
		int minn=2147483647,pos;
		for(int i=k;i<=n;i++){
			if(a[i]<minn){
				minn=a[i];
				pos=i;
			}
		}
		for(int i=pos;i>k;){
			if(i==k+1){
				ans[++top]=k;
				ans[++top]=k;
				i--;
				swap(a[i],a[i+1]);
				swap(a[i],a[i+2]);
				swap(a[i],a[i+1]);
				swap(a[i],a[i+2]);
				break;
			}
			else{
				ans[++top]=i-2;
				i-=2; 
				swap(a[i],a[i+1]);
				swap(a[i],a[i+2]);
			}
		}
	}
	if(a[n]>a[n-1]){
		return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&Q);
	while(Q--){
		top=0;
		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
			vis[c[i]]++;
		}
		for(int i=1;i<=500;i++){
			vis[i]+=vis[i-1];
		}
		for(int i=1;i<=n;i++){
			b[i]=vis[c[i]]--;
		}
		memcpy(a,b,sizeof a);
		if(solve()){
			printf("%d\n",top);
			for(int i=1;i<=top;i++){
				printf("%d ",ans[i]);
			}
			puts("");
		}
		else{
			top=0;
			memset(vis,0,sizeof vis);
			for(int i=1;i<=n;i++){
				if(vis[c[i]]){
					swap(b[vis[c[i]]],b[i]);
					break;
				}
				vis[c[i]]=i;
			}
			memcpy(a,b,sizeof a);
			if(solve()){
				printf("%d\n",top);
				for(int i=1;i<=top;i++){
					printf("%d ",ans[i]);
				}
				puts("");
			}
			else{
				puts("-1");
			}
		}
	}
	return 0;
}