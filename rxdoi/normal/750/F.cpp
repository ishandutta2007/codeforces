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
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=200+19;

Vi E[N];
int vis[N],pre[N];
int a,b,x,y,z,dep,h,chk;

void Output(int x){
	printf("? %d\n",x);
	fflush(stdout);
	E[x].clear();
	for (int k=IN();k--;) E[x].pb(IN());
	if (E[x].size()==2){
		printf("! %d\n",x);
		fflush(stdout);
		chk=1;
	}
}
int go(int x){
	for (int i:E[x]) if (!vis[i]) return i;
}
void findleaf(int &x,int &len){
	int y;
	for (;;){
		len++;
		y=go(x);
		pre[y]=x;
		vis[x=y]=1;
		Output(x);
		if (chk) return;
		if (E[x].size()==1) return;
	}
}
void bfs(int s){
	static int Q[N];
	int f=1,w=0;Q[1]=s;
	while (f>w){
		int x=Q[++w];
		Output(x);
		if (chk) return;
		if (w==6){
			printf("! %d\n",Q[7]);
			fflush(stdout);
			return;
		}
		for (int i:E[x]){
			if (!vis[i]) vis[i]=1,Q[++f]=i;
		}
	}
}
void Main(){
	memset(pre,-1,sizeof(pre));
	chk=0;
	For(i,0,N){
		E[i].clear();
		vis[i]=0;
	}
	h=IN();
	Output(1);
	if (chk) return;
	vis[1]=1;
	x=1;y=1;a=0;b=0;
	if (E[1].size()==1){
		findleaf(y,b);
		if (chk) return;
	} else{
		findleaf(x,a);
		if (chk) return;
		findleaf(y,b);
		if (chk) return;
	}
	h=(a+b)/2;
	if (a>b) swap(a,b),swap(x,y);
	z=y;
	For(i,0,h) z=pre[z];
	vis[z=go(z)]=1;
	for (h++;h<4;h++){
		Output(z);
		if (chk) return;
		x=z;
		For(i,0,h){
			y=go(x);
			pre[y]=x;
			vis[x=y]=1;
			Output(x);
			if (chk) return;
		}
		if (E[x].size()==1){
			z=go(z);
		} else{
			z=x;
			For(i,1,h) z=pre[z];
		}
		For(i,0,h) vis[x]=0,x=pre[x];
		vis[z]=1;
	}
	bfs(z);
}

int main(){
	for (int T=IN();T--;) Main();
}