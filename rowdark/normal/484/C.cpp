#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
char s[1001001];
char es[1001001];
int rmpos[21][1001001];
int n,m;
void build(int a,int b){
	int cnt=0;
	for(int i=0;i<b;++i){
		for(int j=i;j<a;j+=b){
			rmpos[0][j]=cnt-1;
			++cnt;
		}
	}
	for(int i=1;i<=20;++i){
		for(int j=0;j<a;++j){
			if(rmpos[i-1][j]==-1) rmpos[i][j]=-1;
			else rmpos[i][j]=rmpos[i-1][rmpos[i-1][j]];
		}
	}
}

pair<int,int> getpos(int st,int r){
	pair<int,int> now(0,st);
	for(int i=20;i>=0;--i){
		if(now.first+(1<<i)<=r){
			if(rmpos[i][now.second]!=-1){
				now.first+=1<<i;
				now.second=rmpos[i][now.second];
			}
		}
	}
	return now;
}

int main(){
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&m);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		build(a,b);
		for(int i=0;i<n;++i){
			pair<int,int> now=getpos(i<a?i:a-1,min(n-a+1,n-i));
			es[max(0,i-a+1)+now.first+now.second]=s[i];
		}
		for(int i=0;i<n;++i) s[i]=es[i];
		printf("%s\n",s);
	}
	return 0;
}