#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1003
using namespace std;
int n,a[N],ans,x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++)
		scanf("%d",&x),a[i]+=x;
		if(i>1&&a[i]>a[1])ans++;
	}
	printf("%d",ans+1);
}