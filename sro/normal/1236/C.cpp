#include <bits/stdc++.h>
using namespace std;

int a[305][305];
int n;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j%2){
				a[i][j]=(j-1)*n+i;
			}else{
				a[i][j]=j*n+1-i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		puts("");
	}
	return 0;
}