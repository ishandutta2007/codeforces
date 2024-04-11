#include<bits/stdc++.h>
using namespace std;

const int N=300005,M=31;
int n,a[N],b[N],go[N*M][2],sz[N*M],cnt=2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int rt=1;
	for(int i=1;i<=n;i++){
		int now=rt;sz[now]++;
		for(int j=M-1;j>=0;j--){
			int c=b[i]>>j&1;
			if(!go[now][c]){
				go[now][c]=cnt++;
			}
			now=go[now][c];
			sz[now]++;
		}
	}
	for(int i=1;i<=n;i++){
		int x=a[i],ans=0,now=rt;sz[now]--;
		for(int j=M-1;j>=0;j--){
			int c=a[i]>>j&1;
			if(sz[go[now][c]]){
				now=go[now][c];
			}else{
				now=go[now][!c];
				ans+=1<<j;
			}
			sz[now]--;
		}
		printf("%d ",ans);
	}
	printf("\n");
	return 0;
}