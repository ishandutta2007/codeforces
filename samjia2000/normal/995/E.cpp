#include<iostream>
#include<cstdio>
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

const int L = 1e6+5;
const int maxn = 1e5;

int u,v,mo;
int way[L],lst[L];
map<int,int>id;
int k;
int res;
int val[L];

LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

void getext(int x,int l){
	res--;
	if (!res)return;
	if (l>=100)return;
	int v=quickmi(x,mo-2);
	if (!id[v]){
		val[id[v]=++k]=v;
		way[k]=3;
		lst[k]=x;
		getext(v,l+1);
		if (!res)return;
	}
	v=x+1>=mo?0:x+1;
	if (!id[v]){
		val[id[v]=++k]=v;
		way[k]=1;
		lst[k]=x;
		getext(v,l+1);
		if (!res)return;
	}
	v=!x?mo-1:x-1;
	if (!id[v]){
		val[id[v]=++k]=v;
		way[k]=2;
		lst[k]=x;
		getext(v,l+1);
		if (!res)return;
	}
}

int sta[10005],top;
bool sol;

void getans(int x){
	sol=1;
	while(x!=u){
		sta[++top]=way[id[x]];
		x=lst[id[x]];
	}
	printf("%d\n",top);
	fd(i,top,1)printf("%d ",sta[i]);
	putchar('\n');
}

set<int>vis;

void getans(int x,int l){
	if(l>=100)return;
	if (vis.find(x)!=vis.end())return;
	vis.insert(x);
	top++;
	int v;
	sta[top]=3;
	v=quickmi(x,mo-2);
	if (!id[v])getans(v,l+1);
	else getans(v);
	if (sol)return;
	sta[top]=2;
	v=x+1>=mo?0:x+1;
	if(!id[v])getans(v,l+1);
	else getans(v);
	if (sol)return;
	sta[top]=1;
	v=!x?mo-1:x-1;
	if(!id[v])getans(v,l+1);
	else getans(v);
	top--;
}

int main(){
	u=get(),v=get(),mo=get();
	res=maxn;
	getext(u,1);
	getans(v,1);
	return 0;
}