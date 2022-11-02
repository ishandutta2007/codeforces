#include<bits/stdc++.h>
#define N 1000006
using namespace std;
int n,v[N],a[N],c[N][2],f[N];
bool ori[N],mdf[N][2];
inline bool cal(int d,bool a,bool b){
	if(d>2)return a&b;
	if(d>1)return a|b;
	return d?a^b:!a;
}
void dfs(int x){
	if(c[x][0]){
		f[c[x][0]]=f[c[x][1]]=x;
		dfs(c[x][0]);if(v[x])dfs(c[x][1]);
		ori[x]=cal(v[x],ori[c[x][0]],ori[c[x][1]]);
	}
	else ori[x]=a[x];
}
void dfss(int x){
	if(!x)return;
	if(x==1)mdf[x][1]=1;
	else{
		for(int i=0;i<2;i++)
		mdf[x][i]=mdf[f[x]][cal(v[f[x]],i,ori[c[f[x]][c[f[x]][0]==x]])];
	}
	dfss(c[x][0]),dfss(c[x][1]);
}
char op[6];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",op);
		v[i]=op[0]^'A'?op[0]^'O'?op[0]^'X'?0:1:2:3;
		if(op[0]=='I')
		scanf("%d",a+i);
		else scanf("%d",c[i]);
		if(v[i])scanf("%d",c[i]+1);
	}
	dfs(1);dfss(1);
	for(int i=1;i<=n;i++)
	if(!c[i][0])
	printf("%d",mdf[i][a[i]^1]);
}
/*
10
AND 9 4
IN 1
IN 1
XOR 6 5
AND 3 7
IN 0
NOT 10
IN 1
IN 1
AND 2 8

*/