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

const int M = 1000010;
const int N = 100010;
const int INF = 1e+9;

struct node{
	int val,w;
}tree[M*4];
int n,A;
int a[N];
int D;
int tim[M];

int main(){
	n=get();A=get();
	fo(i,1,n)a[i]=get();
	D=1;
	while(D<1000000)D<<=1;
	fo(i,1,D)tree[D+i-1].w=i;
	fo(i,1e+6,D-1)tree[D+i].val=INF;
	tree[D+A-1].val=INF;
	for(int now=D>>1;now;now>>=1)
		fo(i,0,now-1)
		if (tree[(now+i)<<1].val<tree[((now+i)<<1)+1].val)tree[now+i]=tree[(now+i)<<1];
		else tree[now+i]=tree[((now+i)<<1)+1];
	fo(i,1,n){
		if (a[i]!=A){
			tim[a[i]]++;
			int w=D+a[i]-1;
			if (tree[w].val==INF)continue;
			tree[w].val=tim[a[i]];
			for(w>>=1;w;w>>=1)
			if (tree[w<<1].val<tree[(w<<1)+1].val)tree[w]=tree[w<<1];
			else tree[w]=tree[(w<<1)+1];
		}
		else{
			tim[A]++;
			while(tree[1].val<tim[A]){
				int w=D+tree[1].w-1;
				tree[w].val=INF;
				for(w>>=1;w;w>>=1)
				if (tree[w<<1].val<tree[(w<<1)+1].val)tree[w]=tree[w<<1];
				else tree[w]=tree[(w<<1)+1];
			}
		}
	}
	if (tree[1].val==INF)printf("-1\n");
	else printf("%d\n",tree[1].w);
	return 0;
}