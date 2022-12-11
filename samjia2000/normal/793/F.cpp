#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e5+5;
const int B = 350;

int rm[N][B];
int n,m;
int co[N];
int blk;
int g[N][B];
int sta[N],top;

int main(){
	n=get();m=get();
	fo(i,1,m){
		int l=get(),r=get();
		co[r]=l;
	}
	blk=sqrt(n)+1;
	fo(i,1,n)rm[i][0]=g[i][0]=i;
	for(int x=1;x*blk<=n;x++){
		fo(i,1,n)rm[i][x]=rm[i][x-1];
		fo(i,(x-1)*blk+1,x*blk)
		if (co[i])rm[co[i]][x]=i;
		fo(i,1,n)g[i][x]=rm[i][x];
	}
	for(int x=1;x*blk<=n;x++){
		top=0;
		fd(i,x*blk,1){
			sta[++top]=i;
			while(top&&sta[top]<rm[i][x])top--;
			g[i][x]=(top?sta[top]:0);
		}
	}
	for(int T=get();T;T--){
		int l=get(),r=get();
		int x=r/blk;
		int now=g[l][x];
		fo(i,x*blk+1,r)
		if (co[i]<=now&&co[i]>=l)now=i;
		printf("%d\n",now);
	}
	return 0;
}