#include<bits/stdc++.h>
using namespace std;
#define MN 100005
int n,m,a[MN],cnt,ans,last[MN],add[MN],Max[MN];
inline int read(){
	int a=0;char c=getchar();
	while(c>57 or c<48)c=getchar();
	while(47<c and c<58){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i){
		int op,loc,v;
		add[i]=add[i-1];
		op=read();
		if(op==1){
			loc=read();v=read();
			a[loc]=v;
			last[loc]=i;
		}
		else if(op==2)add[i]+=read();
		else{
			loc=read();
			printf("%d\n",a[loc]+add[i]-add[last[loc]]);
		}
	}
	return 0;
}