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
#define lf else if

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

const int N=1e6+19;
const int top=1e6;
const ll oo=1e12;
const ll inf=1e12;

struct node{
	int x,c;
};
vector<node> A[N],B[N];
ll mn[N],pre[N],suf[N];
int n,m,k,d,s,t,c;
ll res;

int main(){
	n=IN(),m=IN(),k=IN();
	For(i,0,m){
		d=IN(),s=IN(),t=IN(),c=IN();
		if (t==0){
			A[d].pb((node){s,c});
		} else{
			B[d].pb((node){t,c});
		}
	}
	pre[0]=1ll*n*oo;
	suf[top+1]=1ll*n*oo;
	For(i,1,n+1) mn[i]=oo;
	for (int i=1;i<=top;i++){
		pre[i]=pre[i-1];
		for (node C:A[i]){
			pre[i]-=mn[C.x];
			mn[C.x]=min(mn[C.x],0ll+C.c);
			pre[i]+=mn[C.x];
		}
	}
	For(i,1,n+1) mn[i]=oo;
	for (int i=top;i>=1;i--){
		suf[i]=suf[i+1];
		for (node C:B[i]){
			suf[i]-=mn[C.x];
			mn[C.x]=min(mn[C.x],0ll+C.c);
			suf[i]+=mn[C.x];
		}
	}
	res=inf;
	for (int i=1;i+k-1<=top;i++){
		res=min(res,pre[i-1]+suf[i+k]);
	}
	if (res==inf) puts("-1");else cout<<res<<endl;
}