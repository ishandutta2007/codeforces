#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a,b,n,i,sum,A[N],ta,B[N],tb;
int main(){
	scanf("%d%d",&a,&b);
	for(i=0;(sum+=i)<=a+b;i++);
	i--;
	for(;i;i--){
		if(a>=i)A[ta++]=i,a-=i;
		else B[tb++]=i;
	}
	printf("%d\n",ta);
	for(int i=0;i<ta;i++)printf("%d ",A[i]);
	printf("\n%d\n",tb);
	for(int i=0;i<tb;i++)printf("%d ",B[i]);
}