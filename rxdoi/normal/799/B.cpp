#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=200000+19;
const int oo=(1<<30)-1;

queue<int> Q[4];
int p[N],a[N],b[N],id[N],vis[N];
int n;

bool cmp(int x,int y){
	return p[x]<p[y];
}

int main(){
	n=IN();
	For(i,1,n+1) p[i]=IN();
	For(i,1,n+1) a[i]=IN();
	For(i,1,n+1) b[i]=IN();
	For(i,1,n+1) id[i]=i;
	sort(id+1,id+n+1,cmp);
	For(i,1,n+1){
		int x=id[i];
		Q[a[x]].push(x);
		Q[b[x]].push(x);
	}
	for (int q=IN();q--;){
		int c=IN();
		while (!Q[c].empty()&&vis[Q[c].front()]) Q[c].pop();
		if (Q[c].empty()){
			printf("-1 ");
		} else{
			printf("%d ",p[Q[c].front()]);
			vis[Q[c].front()]=1;
		}
	}
	puts("");
}