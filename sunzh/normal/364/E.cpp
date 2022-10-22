#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m,K;
long long ans;
char str[3010][3010];
int sum[3010][3010];
int ls[11],rs[11];
int getsum(int ux,int uy,int dx,int dy){
//	printf("%d %d %d %d ,sum=%d\n",ux,uy,dx,dy,sum[dx][dy]-sum[ux-1][dy]-sum[dx][uy-1]+sum[ux-1][uy-1]);
	return sum[dx][dy]-sum[ux-1][dy]-sum[dx][uy-1]+sum[ux-1][uy-1];
}
void Calc(int ux,int uy,int dx,int dy){
//	printf("%d %d %d %d\n",ux,uy,dx,dy);
	int N=dx-ux+1,M=dy-uy+1;
	if(N==1&&M==1){
		if(str[ux][uy]==K+'0') ++ans;
//		printf("ret:%d %d\n",ux,uy);
		return ;
	}
	if(N>M){
		int mid=ux+dx>>1;
		Calc(ux,uy,mid,dy);Calc(mid+1,uy,dx,dy); 
		for(int i=uy;i<=dy;++i){
			for(int j=0;j<=K+1;++j){
				ls[j]=ux-1,rs[j]=dx+1;
			}
//			printf("i:%d\n",i);
			for(int j=i;j<=dy;++j){
				for(int k=0;k<=K+1;++k){
					while(ls[k]<mid&&getsum(ls[k]+1,i,mid,j)>=k) ++ls[k];
					while(rs[k]>mid+1&&getsum(mid+1,i,rs[k]-1,j)>=k) --rs[k];
				}
				for(int k=0;k<=K;++k){
					ans+=1ll*(ls[k]-ls[k+1])*(rs[K-k+1]-rs[K-k]);
				}
			}
		}
	} 
	else{
		int mid=uy+dy>>1;
		Calc(ux,uy,dx,mid);Calc(ux,mid+1,dx,dy); 
		for(int i=ux;i<=dx;++i){
			for(int j=0;j<=K+1;++j){
				ls[j]=uy-1,rs[j]=dy+1;
			}
//			printf("i:%d\n",i);
			for(int j=i;j<=dx;++j){
				for(int k=0;k<=K+1;++k){
//					printf("j:%d,k:%d\n",j,k);
					while(ls[k]<mid&&getsum(i,ls[k]+1,j,mid)>=k) ++ls[k];
					while(rs[k]>mid+1&&getsum(i,mid+1,j,rs[k]-1)>=k) --rs[k];
				}
				for(int k=0;k<=K;++k){
					ans+=1ll*(ls[k]-ls[k+1])*(rs[K-k+1]-rs[K-k]);
				}
			}
		}
	}
//		printf("ret:%d %d\n",ux,uy);
}
int main(){
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i){
		scanf("%s",str[i]+1);
		for(int j=1;j<=m;++j) sum[i][j]=str[i][j]-'0';
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	Calc(1,1,n,m);
	printf("%lld\n",ans);
}