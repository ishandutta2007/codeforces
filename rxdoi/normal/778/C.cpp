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

const int N=6e5+19;

int sz[N],val[N],a[N],b[N],trs[N][26];
int n,x,y,res,top;
char s[10];

void calc(int x,int y,int dep){
	val[dep]++;
	For(i,0,26)
		if (trs[x][i]){
			if (!trs[y][i]){
				top++;a[top]=y;b[top]=i;
				trs[y][i]=trs[x][i];
			} else{
				calc(trs[x][i],trs[y][i],dep);
			}
		}
}
void dfs(int x,int dep){
	int son=0;
	sz[x]=1;
	For(i,0,26){
		int y=trs[x][i];
		if (!y) continue;
		dfs(y,dep+1);
		sz[x]+=sz[y];
		son=y;
		//if (sz[y]>sz[son]) son=y;
	}
	if (son) val[dep]++;
	For(i,0,26){
		int y=trs[x][i];
		if (!y||y==son) continue;
		calc(y,son,dep);
	}
	for (;top;top--){
		trs[a[top]][b[top]]=0;
	}
}

int main(){
	n=IN();
	For(i,1,n){
		x=IN(),y=IN();
		scanf("%s",s);
		trs[x][s[0]-'a']=y;
	}
	dfs(1,1);
	res=0;
	For(i,1,n+1) if (val[i]>val[res]) res=i;
	printf("%d\n",n-val[res]);
	printf("%d\n",res);
}