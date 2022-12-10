#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<string>
#include<bitset>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
//#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
//typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=6000+19;
const int M=6000+19;

struct edge{
	int x,y;
} e[M],E[M];
int pa[N][200+19],pb[N][200+19];
int ta[N],tb[N],da[N],db[N],da2[N],db2[N],col[N];
int na,nb,m,k,ca,cb,ans,x,y;
map<pii,int> A;

void dfs1(int,int,int);
void dfs2(int y,int ca,int cb){
	int x=pb[y][ca];
	if (!x){
		return;
	} else{
		pa[x][ca]=0;
		pb[y][ca]=0;
		dfs1(x,ca,cb);
		pa[x][cb]=y;
		pb[y][cb]=x;
	}
}
void dfs1(int x,int ca,int cb){
	int y=pa[x][cb];
	if (!y){
		return;
	} else{
		pa[x][cb]=0;
		pb[y][cb]=0;
		dfs2(y,ca,cb);
		pa[x][ca]=y;
		pb[y][ca]=x;
	}
}

int main(){
	na=IN(),nb=IN(),m=IN(),k=IN();
	For(i,0,m){
		x=IN(),y=IN();
		e[i]=(edge){x,y};
		da[x]++;
		db[y]++;
		if (!ta[x]||da2[ta[x]]==k) ta[x]=++ca;
		if (!tb[y]||db2[tb[y]]==k) tb[y]=++cb;
		E[i]=(edge){ta[x],tb[y]};
		A[mp(ta[x],tb[y])]=i;
		da2[ta[x]]++;
		db2[tb[y]]++;
		dprintf("%d %d\n",ta[x],tb[y]);
	}
	For(i,1,na+1) if (da[i]%k!=0) ans++;
	For(i,1,nb+1) if (db[i]%k!=0) ans++;
	For(w,0,m){
		int ca=-1,cb=-1;
		x=E[w].x,y=E[w].y;
		For(i,0,k) if (!pa[x][i]) {ca=i;break;}
		For(i,0,k) if (!pb[y][i]) {cb=i;break;}
		assert(ca!=-1&&cb!=-1);
		if (ca==cb){
			pa[x][ca]=y;
			pb[y][cb]=x;
		} else{
			if (ca<cb){
				dfs2(y,ca,cb);
				pa[x][ca]=y;
				pb[y][ca]=x;
			} else{
				dfs1(x,ca,cb);
				pa[x][cb]=y;
				pb[y][cb]=x;
			}
		}
	}
	memset(col,-1,sizeof(col));
	For(i,1,ca+1){
		For(j,0,k) if (pa[i][j]){
			col[A[mp(i,pa[i][j])]]=j;
		}
	}
	printf("%d\n",ans);
	For(i,0,m) printf("%d ",col[i]+1);
	puts("");
}