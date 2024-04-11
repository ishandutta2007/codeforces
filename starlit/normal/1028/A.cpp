#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,l,r,c1,c2,k;
char S[120];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		l=r=0;scanf("%s",S+1);
		for(int j=1;j<=m;j++)
		if(S[j]=='B'){
			if(!l)l=j;
			r=j;
		}
		if(l){
			if(!c1)c1=i;
			c2=i;
			k=l+r>>1;
		}
	}
	printf("%d %d",c1+c2>>1,k);
}