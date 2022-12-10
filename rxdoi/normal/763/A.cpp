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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2e5+19;

struct edge{
	int x,y;
} e[N];

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],col[N];
int n,cnt;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
bool dfs(int x,int fa,int c){
	if (col[x]!=c) return 0;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa){
			if (!dfs(y,x,c)) return 0;
		}
	return 1;
}
bool check(int x){
	for (int i=las[x],y;~i;i=E[i].nxt){
		y=E[i].y;
		if (!dfs(y,x,col[y])) return 0;
	}
	return 1;
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n){
		e[i]=(edge){IN(),IN()};
		Link(e[i].x,e[i].y);
	}
	For(i,1,n+1) col[i]=IN();
	For(i,1,n)
		if (col[e[i].x]!=col[e[i].y]){
			if (check(e[i].x)){
				puts("YES");
				printf("%d\n",e[i].x);
				return 0;
			}
			if (check(e[i].y)){
				puts("YES");
				printf("%d\n",e[i].y);
				return 0;
			}
			puts("NO");
			return 0;
		}
	puts("YES");
	puts("1");
}