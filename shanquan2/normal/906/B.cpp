#include<bits/stdc++.h>
using namespace std;

int n,m,a[15];
bool e[15][15];
int get(int x,int y){
	return x*m+y;
}
int main(){
	scanf("%d%d",&n,&m);
	if(n<=3&&m<=3){
		for(int i=0;i<n*m;i++)a[i]=i;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++){
			int u=get(i,j),v;
			if(j<m-1){
				v=get(i,j+1);
				e[u][v]=1;
			}
			if(i<n-1){
				v=get(i+1,j);
				e[u][v]=1;
			}
			if(j){
				v=get(i,j-1);
				e[u][v]=1;
			}
			if(i){
				v=get(i-1,j);
				e[u][v]=1;
			}
		}
		for(;;){
			bool f=1;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++){
				if(i<n-1&&e[a[get(i,j)]][a[get(i+1,j)]]){f=0;break;}
				if(j<m-1&&e[a[get(i,j)]][a[get(i,j+1)]]){f=0;break;}
			}
			if(f){
				printf("YES\n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++)
						printf("%d ",a[get(i,j)]+1);
					printf("\n");
				}
				return 0;
			}
			if(!next_permutation(a,a+n*m))break;
		}
	}else if(n>=4){
		printf("YES\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x=i*2+1,y=j;
				if(x>=n)x=(i-n/2)*2;
				if(y&1){
					x=i*2;
					if(n%2==0&&x<n)x=(n/2-i-1)*2;
					if(x>=n)if(n&1)x=1+(i-n/2-1)*2;else x=1+(n-i-1)*2;
				}
				printf("%d ",get(x,y)+1);
			}
			printf("\n");
		}
		return 0;
	}else if(m>=4){
		printf("YES\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int x=i,y=j*2+1;
				if(y>=m)y=(j-m/2)*2;
				if(x&1){
					y=j*2;
					if(m%2==0&&y<m)y=(m/2-j-1)*2;
					if(y>=m)if(m&1)y=1+(j-m/2-1)*2;else y=1+(m-j-1)*2;
				}
				printf("%d ",get(x,y)+1);
			}
			printf("\n");
		}
		return 0;
	}
	printf("NO\n");
	return 0;
}