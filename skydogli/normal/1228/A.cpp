#include<bits/stdc++.h>
using namespace std;
int vis[15],l,r;
int main(){
	scanf("%d%d",&l,&r);
	for(int i=l;i<=r;++i){
		memset(vis,0,sizeof(vis));
		int tmp=i,bol=0;
		while(tmp){
			if(vis[tmp%10]){
				bol=1;
				break;
			}
			vis[tmp%10]=1;
			tmp/=10;
		}
		if(!bol){
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}