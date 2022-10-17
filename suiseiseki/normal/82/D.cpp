#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int F[1100][1100];
int A[1100];
int n;
int dp(int i,int j){
	if(j>n){
		return A[i];
	}
	if(j==n){
		return max(A[i],A[j]);
	}
	int &ret=F[i][j];
	if(ret!=-1){
		return ret;
	}
	ret=max(A[j],A[j+1])+dp(i,j+2);
	ret=min(ret,max(A[i],A[j])+dp(j+1,j+2));
	ret=min(ret,max(A[i],A[j+1])+dp(j,j+2));
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	memset(F,-1,sizeof F);
	printf("%d\n",dp(1,2));
	int i=1,j=2;
	while(1){
		if(j>n){
			printf("%d\n",i);
			break;
		}
		else if(j==n){
			printf("%d %d\n",i,j);
			break;
		}
		else{
			int& ret=F[i][j];
			if(ret==max(A[j],A[j+1])+dp(i,j+2)){
				printf("%d %d\n",j,j+1);
				j=j+2;
			}
			else if(ret==max(A[i],A[j])+dp(j+1,j+2)){
				printf("%d %d\n",i,j);
				i=j+1;
				j=j+2;
			}
			else{
				printf("%d %d\n",i,j+1);
				i=j;
				j=j+2;
			}
		}
	}
	return 0;
}