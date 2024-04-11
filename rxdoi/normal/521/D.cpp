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
typedef long double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=1e5+19;

int T[N],A[N],n,m,k,o,x,v,cnt;
pii mx[N];
pair<db,int> val[N];
vector<pii> V[N];
Vi res;
ll pre;

bool cmp(int a,int b){
	return T[a]<T[b];
}

int main(){
	n=IN(),m=IN(),k=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,m+1){
		T[i]=o=IN();
		x=IN(),v=IN();
		if (o==1){
			mx[x]=max(mx[x],mp(v,i));
		}
		if (o==2){
			V[x].pb(mp(v,i));
		}
		if (o==3){
			val[++cnt]=mp(v,i);
		}
	}
	For(i,1,n+1){
		if (mx[i].fi>A[i]){
			mx[i].fi-=A[i];
			V[i].pb(mx[i]);
		}
		sort(V[i].begin(),V[i].end());
		reverse(V[i].begin(),V[i].end());
		pre=A[i];
		For(j,0,V[i].size()){
			val[++cnt]=mp(1.0*(pre+V[i][j].fi)/pre,V[i][j].se);
			pre+=V[i][j].fi;
		}
	}
	sort(val+1,val+cnt+1);
	for (int i=cnt;i>=1&&k>=1;i--,k--) res.pb(val[i].se);
	sort(res.begin(),res.end(),cmp);
	printf("%d\n",res.size());
	For(i,0,res.size()) printf("%d ",res[i]);
	puts("");
}