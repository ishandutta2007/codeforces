#include <cstdio>
#include <random>
#include <chrono>
#include <cstring>
#include <algorithm>
const int Maxm=60;
const int Maxp=15;
const int Maxn=200000;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int n,m,p;
bool val[Maxn+5][Maxm+5];
int p_lis[Maxn+5];
int st[Maxp+5],top;
int sz[1<<Maxp|5];
int f[1<<Maxp|5];
bool ans_lis[Maxm+5];
void init(){
	for(int i=1;i<(1<<Maxp);i++){
		sz[i]=sz[i-(i&(-i))]+1;
	}
}
int main(){
	init();
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int a;
			scanf("%1d",&a);
			val[i][j]=a;
		}
		p_lis[i]=i;
	}
	std::shuffle(p_lis+1,p_lis+1+n,rnd);
	int ans=0;
	for(int i=1;i<=std::min(n,60);i++){
		top=0;
		for(int j=1;j<=m;j++){
			if(val[p_lis[i]][j]){
				st[top++]=j;
			}
		}
		memset(f,0,sizeof f);
		for(int j=1;j<=n;j++){
			int mask=0;
			for(int k=0;k<top;k++){
				if(val[j][st[k]]){
					mask|=(1<<k);
				}
			}
			f[mask]++;
		}
		for(int j=0;j<top;j++){
			for(int k=0;k<(1<<top);k++){
				if(((k>>j)&1)==0){
					f[k]+=f[k+(1<<j)];
				}
			}
		}
		for(int j=0;j<(1<<top);j++){
			if(f[j]>=((n+1)>>1)){
				if(sz[j]>ans){
					ans=sz[j];
					for(int k=1;k<=m;k++){
						ans_lis[k]=0;
					}
					for(int k=0;k<top;k++){
						if((j>>k)&1){
							ans_lis[st[k]]=1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d",ans_lis[i]);
	}
	puts("");
	return 0;
}