#include<iostream>
#include<cstdio>
#include<cstring>
#define N 134000
using namespace std;
int n,xx1,xx2,yy1,yy2;
struct db{
	int fi,se;
	db(){fi=se=-2e9;}
	inline void ins(int x){
		if(x>=fi)se=fi,fi=x;
		else if(x>se)se=x;
	}
	int res(int x){
		return fi==x?se:fi;
	}
}xmn,ymn,xmx,ymx;
int X1[N],X2[N],Y1[N],Y2[N];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",X1+i,Y1+i,X2+i,Y2+i);
		xmn.ins(-X2[i]),xmx.ins(X1[i]);
		ymn.ins(-Y2[i]),ymx.ins(Y1[i]);
	}
	for(int i=0;i<n;i++){
		xx1=-xmn.res(-X2[i]);
		xx2=xmx.res(X1[i]);
		yy1=-ymn.res(-Y2[i]);
		yy2=ymx.res(Y1[i]);
		if(xx2<=xx1&&yy2<=yy1){
			printf("%d %d\n",xx2,yy2);
			return 0;
		}
	}
}