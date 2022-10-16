#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define INF 0x3f3f3f3f
typedef long long ll;
struct Queue{
	int id,val;
}que[maxn];
int a[maxn],ans[maxn];
int main(){
	int n; scanf("%d",&n);
	int mx=0,mi=INF;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);	
	} 
	if(mx<=mi*2){
		for(int i=1;i<n;i++) printf("-1 ");
		printf("-1\n");
	}
	else{
		int head=1,tail=0;
		for(int i=n+1;i<=3*n;i++) a[i]=a[i-n];
		for(int i=1;i<=3*n;i++){
			while(head<=tail && que[tail].val<a[i]) tail--;
			que[++tail].val=a[i]; que[tail].id=i;
			while(que[head].val>a[i]*2){
				ans[que[head].id]=i-que[head].id;
				head++;
			}
		}
		for(int i=3*n;i>=1;i--){
			if(ans[i]==0) ans[i]=ans[i+1]+1;
		}
		for(int i=1;i<=n;i++){
			if(i==1) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}