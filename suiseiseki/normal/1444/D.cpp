#include <bitset>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int Maxn=1000;
int a[Maxn+5],b[Maxn+5];
int n,m;
int sum_1,sum_2;
bitset<Maxn*Maxn+5> f[Maxn+5];
int lis[2][2][Maxn+5],lis_len[2][2];
bool work(int *a,int sum,int d){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i]=(f[i-1]|(f[i-1]<<a[i]));
	}
	if(f[n][sum]==0){
		return 0;
	}
	for(int i=n;i>0;i--){
		if(sum>=a[i]&&f[i-1][sum-a[i]]){
			sum-=a[i];
			lis[d][0][++lis_len[d][0]]=a[i];
		}
		else{
			lis[d][1][++lis_len[d][1]]=a[i];
		}
	}
	return 1;
}
int d[2][Maxn+5];
int d_len[2];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(lis_len,0,sizeof lis_len);
		memset(d_len,0,sizeof d_len);
		sum_1=sum_2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum_1+=a[i];
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&b[i]);
			sum_2+=b[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		if((sum_1&1)||(sum_2&1)||n!=m){
			puts("No");
			continue;
		}
		sum_1>>=1;
		sum_2>>=1;
		if(!work(a,sum_1,0)){
			puts("No");
			continue;
		}
		if(!work(b,sum_2,1)){
			puts("No");
			continue;
		}
		puts("Yes");
		if(lis_len[0][0]<=lis_len[1][0]){
			for(int i=1;i<=lis_len[0][0];i++){
				d[0][++d_len[0]]=lis[0][0][i];
			}
			for(int i=1;i<=lis_len[0][1];i++){
				d[0][++d_len[0]]=-lis[0][1][i];
			}
			for(int i=lis_len[1][0];i>0;i--){
				d[1][++d_len[1]]=lis[1][0][i];
			}
			for(int i=lis_len[1][1];i>0;i--){
				d[1][++d_len[1]]=-lis[1][1][i];
			}
			int x=0,y=0;
			for(int i=1;i<=n;i++){
				x+=d[0][i];
				printf("%d %d\n",x,y);
				y+=d[1][i];
				printf("%d %d\n",x,y);
			}
		}
		else{
			for(int i=1;i<=lis_len[1][0];i++){
				d[0][++d_len[0]]=lis[1][0][i];
			}
			for(int i=1;i<=lis_len[1][1];i++){
				d[0][++d_len[0]]=-lis[1][1][i];
			}
			for(int i=lis_len[0][0];i>0;i--){
				d[1][++d_len[1]]=lis[0][0][i];
			}
			for(int i=lis_len[0][1];i>0;i--){
				d[1][++d_len[1]]=-lis[0][1][i];
			}
			int x=0,y=0;
			for(int i=1;i<=n;i++){
				x+=d[0][i];
				printf("%d %d\n",y,x);
				y+=d[1][i];
				printf("%d %d\n",y,x);
			}
		}
	}
	return 0;
}