#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

const int len=200000;
inline char nc(){
	static char buf[len],*b=buf+len;
	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
	return *b++;
}
int IN(){
	int c,f,x;
	while (!isdigit(c=nc())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=nc())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
void write(int x){
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=1000000+19;

Vi V;
struct edge {int x,y;} e[N];
int top,n,m;

struct USet{
	int fa[N],rk[N],d[N],S[2*N];
	int getf(int x){
		return fa[x]==x?x:getf(fa[x]);
	}
	int getdis(int x){
		int res=0;
		while (fa[x]!=x) res^=d[x],x=fa[x];
		return res;
	}
	void Union(int x,int y,int dis){
		x=getf(x),y=getf(y);
		if (rk[x]>rk[y]) swap(x,y);
		if (rk[x]==rk[y]) rk[y]++,S[++top]=-y;
		fa[x]=y;d[x]=dis;S[++top]=x;
	}
	void Resume(int pre){
		while (top!=pre){
			int x=S[top--];
			if (x>0) fa[x]=x,d[x]=0;else rk[-x]--;
		}
	}
} U;

bool calc(int L,int R){
	For(i,L,R+1){
		int x=e[i].x,y=e[i].y,d;
		d=U.getdis(x)^U.getdis(y);
		if (U.getf(x)==U.getf(y)){
			if (!d) return 0;
		} else{
			U.Union(x,y,d^1);
		}
	}
	return 1;
}
void work(int L,int R){
	if (L==R){
		V.pb(L);return;
	}
	int pre=top;
	if (calc(Mid+1,R)) work(L,Mid);
	U.Resume(pre);
	if (calc(L,Mid)) work(Mid+1,R);
	U.Resume(pre);
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1) e[i]=(edge){IN(),IN()};
	For(i,1,n+1) U.fa[i]=i;
	if (m==0) return puts("0"),0;
	work(1,m);
	printf("%d\n",V.size());
	For(i,0,V.size()){
		write(V[i]);
		putchar(" \n"[i==V.size()-1]);
	}
}