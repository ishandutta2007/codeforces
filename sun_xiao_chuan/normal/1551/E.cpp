#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,sum,a[2050],res;

int f[2050];

void add(int *f,int x,int y){for(;x<=n;x+=(-x&x)){f[x]=min(f[x],y);}}
int get(int *f,int x,int y=0){for(;x;x-=(-x&x)){y=min(y,f[x]);}return y;}

int main(){
	scanf("%d",&t);
	while(t--){
		res=1145141919;
		memset(f,0,sizeof(f));
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]>i){continue;}
			for(j=0;j<i;j++){
				if(a[j]>=a[i]){continue;}
				if((a[i]-a[j])>(i-j)){continue;}
				f[i]=max(f[i],f[j]+1);
			}
		}
		for(i=1;i<=n;i++){
			//printf("a%d %d %d\n",i,f[i],m);
			if(f[i]>=m){
				res=min(res,i-a[i]);
			}
		}
		if(res==1145141919){
			puts("-1");
		}
		else{
			printf("%d\n",res);
		}
	}
}