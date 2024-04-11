#include<iostream>
#include<cstdio>
#include<cstring>
#define N 20
using namespace std;
int n,mn,mno,now,qwq;
int main(){
	scanf("%d",&n);mn=n+2;
	for(int i=1;i<=n;i++)
	now=i+(n+i-1)/i,
	mn>now?mn=now,mno=i:0;
	qwq=n;
	for(int i=0;i<n;i+=mno){
		qwq-=mno;qwq=max(0,qwq);
		for(int j=1;j<=mno&&i+j<=n;j++)
		printf("%d ",qwq+j);
	}
}
//2 3 4 4 5 5 6 6 6
/*
min(s+up(n/s))
7 8 9 4 5 6 1 2 3
*/