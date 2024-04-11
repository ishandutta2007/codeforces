#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int read(){
    int nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
void dfs(int n,int v){
	if(!n) return;
	if(n==3) printf("%d %d %d ",v,v,v*3);
	else if(n==2) printf("%d %d \n",v,v<<1);
	else if(n==1) printf("%d ",v);
	else{for(int i=1;i<=(n+1)/2;i++) printf("%d ",v); dfs(n/2,v*2);}
}
int m;
int main(){
	m=read();
	if(m==1) puts("1");
	else if(m==2) puts("1 2");
	else if(m==3) puts("1 1 3");
	else dfs(m,1);
}