#include<iostream>
#include<cstdio>
#include<cstring>
#define N 141000
using namespace std;
int n,loc,B[N];
long long lst,x,A[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",B+i);
		if(i>1&&B[i]>B[i-1])loc=i;
	}
	B[0]=B[n];
	if(B[1]>B[n])loc=1;
	if(!loc){
		if(B[1])puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)printf("1 ");
		}
		return 0;
	}
	A[loc]=lst=B[loc];
	for(int i=loc-1;;i--){
		if(!i)i=n;
		if(i==loc)break;
		if(B[i-1]<B[i])x=0;
		else x=(B[i-1]-B[i])/lst+1;
		A[i]=x*lst+B[i];
		lst=A[i];
	}
	puts("YES");
	for(int i=1;i<=n;i++)printf("%I64d ",A[i]);
}