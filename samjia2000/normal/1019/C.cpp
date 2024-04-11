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

const int N = 1e6+5;

int n,m;
struct edge{
	int x,nxt;
}e[N];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

bool used[N];
int be[N];

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y);
	}
	fo(i,1,n)
	if (!be[i]){
		be[i]=i;
		for(int p=h[i];p;p=e[p].nxt)
		if (!be[e[p].x])be[e[p].x]=i;
		used[i]=1;
	}
	fd(i,n,1)
	if (be[i]==i){
		if (used[i])for(int p=h[i];p;p=e[p].nxt)used[e[p].x]=0;
	}
	int k=0;
	fo(i,1,n)if (used[i])k++;
	printf("%d\n",k);
	fo(i,1,n)if (used[i])printf("%d ",i);
	return 0;
}