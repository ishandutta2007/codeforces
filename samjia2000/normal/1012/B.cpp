#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

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

const int N = 4e5+5;

int n,m;
int fa[N];
int ad[N];
int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

bool vis[N];

int main(){
	n=get();m=get();
	fo(i,1,n+m)fa[i]=i;
	for(int q=get();q;q--){
		int x=get(),y=get()+n;
		int tx=getfather(x),ty=getfather(y);
		fa[tx]=ty;
	}
	int ans=0;
	fo(i,1,n+m)
	if (getfather(i)==i)ans++;
	ans--;
	printf("%d\n",ans);
	return 0;
}