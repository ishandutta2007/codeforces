#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
int a[2][105],n,p1,p2,p3;//^ | &
char s[10];
int main(){
	scanf("%d",&n);
	for(int j=0;j<=9;++j)a[1][j]=1;
	rep(i,n){
		int x;
		scanf("%s %d",s+1,&x);
		for(int j=0;j<=9;++j){
			if(s[1]=='|'){
				if(x&(1<<j))a[0][j]=a[1][j]=1;
			}
			if(s[1]=='^'){
				if(x&(1<<j))a[0][j]^=1,a[1][j]^=1;
			}
			if(s[1]=='&'){
				if((x&(1<<j))==0)a[0][j]=a[1][j]=0;
			}
		}
	}
	for(int j=0;j<=9;++j){
		if(a[0][j]==0&&a[1][j]==0);//p3|=1<<j;
		if(a[0][j]==0&&a[1][j]==1)p3|=1<<j;
		if(a[0][j]==1&&a[1][j]==0)p1|=1<<j,p3|=1<<j;
		if(a[0][j]==1&&a[1][j]==1)p2|=1<<j,p3|=1<<j;
	}
	puts("3");
	printf("^ %d\n",p1);
	printf("| %d\n",p2);
	printf("& %d\n",p3);
	return 0;
}