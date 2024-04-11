#include<cstdio>
using namespace std;

int a[31];
bool map[1000][1000]={0};
int main(){
	int k;scanf("%d",&k);
	int m=0,t=0;
	while(k>0){
		if(k&1)a[t++]=m;
		k/=2;m++;
	}
//	printf("%d\n",m);
//	for(int i=0;i<t;i++)printf("%d\n",a[i]);
	int n=2+m*2;
	map[0][2]=map[2][0]=map[0][3]=map[3][0]=1;
	for(int i=1;i<m;i++){
		map[i*2][i*2+2]=map[i*2+2][i*2]=map[i*2][i*2+3]=map[i*2+3][i*2]=1;
		map[i*2+1][i*2+2]=map[i*2+2][i*2+1]=map[i*2+1][i*2+3]=map[i*2+3][i*2+1]=1;
	}
	int p=a[t-1];
	for(int i=0;i<t-1;i++){
		int u=a[i];
		map[u*2+2][n]=map[n][u*2+2]=1;n++;
		for(int j=1;j<p-a[i];j++)
			map[n-1][n]=map[n][n-1]=1,n++;
		map[n-1][1]=map[1][n-1]=1;
	}
	map[a[t-1]*2+2][1]=map[1][a[t-1]*2+2]=1;
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			if(map[i][j])printf("Y");else printf("N");
		printf("\n");
	}
	return 0;
}