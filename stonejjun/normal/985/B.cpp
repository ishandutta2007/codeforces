#include<stdio.h>

int n,m,cnt[2000],sum[2000];
char arr[2000][2000];

int main(){
	scanf("%d %d", &n,&m);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c", &arr[i][j]);
			arr[i][j]-='0';
		}
		getchar();
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			sum[i]+=arr[j][i];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(sum[i]-arr[j][i]!=0) cnt[j]++;
		}
	}
	for(int i=0;i<n;i++){
		if(cnt[i]==m){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}