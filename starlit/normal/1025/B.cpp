#include<iostream>
#include<cstdio>
#include<cstring>
#define N 150005
using namespace std;
int n,a[N],b[N],x,y,j;
void test(int i){
	for(j=1;j<n;j++)
	if(a[j]%i&&b[j]%i)break;
	if(j==n){
		printf("%d",i);
		exit(0);
	}
}
void cal(int x){
	for(int i=2;i*i<=x&&x>1;i++)
	if(x%i==0){
		for(;x%i==0;x/=i);
		test(i);
	}
	if(x>1)test(x);
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;i++)
	scanf("%d%d",a+i,b+i);
	cal(x),cal(y);
	puts("-1");
}