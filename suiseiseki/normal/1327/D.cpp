#include <cstdio>
const int Maxn=200000;
int t,n,m,p[Maxn+5],c[Maxn+5],vis[Maxn+5],ok[Maxn+5],nw[Maxn+5];
bool chk(int x,int len){
	int flg=0;
	for(int i=0;i<x;i++){
		int cur=i,flg2=1;
		for(int j=0;j<len/x;j++){
			if(c[nw[cur]]!=c[nw[(cur+x)%len]]){
				flg2=0;
				break;
			}
			cur+=x;
		}
		if(flg2){
			flg=1;
			break;
		}
	}
	return flg;
}
int main(){
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&p[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				int cur=i,len=0;
				while(!vis[cur]){
					vis[cur]=1;
					nw[len++]=cur;
					cur=p[cur];
				}
				for(int j=1;j*j<=len;j++){
					if(len%j){
						continue;
					}
					if(chk(j,len)){
						ok[j]=1;
					}
					if(chk(len/j,len)){
						ok[len/j]=1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(ok[i]){
				printf("%d\n",i);
				break;
			}
		}
		for(int i=1;i<=n;i++){
			ok[i]=vis[i]=0;
		}
	}
	return 0;
}