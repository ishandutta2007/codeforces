#include <cstdio>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
const int Maxn=1000;
const double Inf=1e18;
int n;
double p[Maxn+5][Maxn+5];
double dis[Maxn+5],sum[Maxn+5],pr[Maxn+5];
bool vis[Maxn+5];
int lis[Maxn+5];
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int now;
			read(now);
			p[i][j]=now*0.01;
		}
		sum[i]=pr[i]=1.0;
	}
	vis[n]=1;
	lis[1]=n;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			sum[j]+=dis[lis[i-1]]*p[j][lis[i-1]]*pr[j];
			pr[j]*=(1-p[j][lis[i-1]]);
			dis[j]=sum[j]/(1-pr[j]);
		}
		int pos=0;
		for(int j=1;j<=n;j++){
			if(vis[j]){
				continue;
			}
			if(pos==0||dis[pos]>dis[j]){
				pos=j;
			}
		}
		vis[pos]=1;
		lis[i]=pos;
	}
	printf("%.10lf\n",dis[1]);
	return 0;
}