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

const int N = 100010;

int n,m;
struct edge{
	int x,nxt;
}e[N];
int h[N],tot;
int c[N];
int label[N];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		c[x]++;
		inse(y,x);
	}
	set<int>s;
	fo(i,1,n)
	if (!c[i])s.insert(i);
	fd(i,n,1){
		set<int>::iterator u=s.end();
		u--;
		int x=*u;
		s.erase(u);
		label[x]=i;
		for(int p=h[x];p;p=e[p].nxt){
			c[e[p].x]--;
			if (!c[e[p].x])s.insert(e[p].x);
		}
	}
	fo(i,1,n-1)printf("%d ",label[i]);
	printf("%d\n",label[n]);
	return 0;
}