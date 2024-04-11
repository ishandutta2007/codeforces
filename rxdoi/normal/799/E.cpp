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
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

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

const int N=200000+19;

vector<int> V[2][2];
vector<ll> s[2][2];
int c[N],va[N],vb[N],id[N],rnk[N];
int n,m,k;

bool cmp(int x,int y){
	return c[x]<c[y];
}

ll sum[N*4],res=1ll<<60;
int cnt[N*4];

void Modify(int x,int L,int R,int Qx,int Qv){
	if (L==R){
		cnt[x]=Qv;
		sum[x]=Qv*c[id[L]];
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid,Qx,Qv):Modify(Rsn,Mid+1,R,Qx,Qv);
	sum[x]=sum[Lsn]+sum[Rsn];
	cnt[x]=cnt[Lsn]+cnt[Rsn];
}
ll Query(int x,int L,int R,int k){
	if (L==R) return sum[x];
	if (k<=cnt[Lsn]){
		return Query(Lsn,L,Mid,k);
	} else{
		return sum[Lsn]+Query(Rsn,Mid+1,R,k-cnt[Lsn]);
	}
}

void cal(int x){
	if (x>V[1][1].size()) return;
	if (k-x>V[1][0].size()) return;
	if (k-x>V[0][1].size()) return;
	int num=m-x-2*max(k-x,0);
	if (num<0||num>cnt[1]) return;
	ll tmp=0;
	if (x) tmp+=s[1][1][x-1];
	if (max(k-x,0)){
		tmp+=s[1][0][max(k-x,0)-1];
		tmp+=s[0][1][max(k-x,0)-1];
	}
	if (num) tmp+=Query(1,1,n,num);
	res=min(res,tmp);
}

int main(){
	n=IN(),m=IN(),k=IN();
	For(i,1,n+1){
		c[i]=IN();
		id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	For(i,1,n+1) rnk[id[i]]=i;
	for (int a=IN();a--;) va[IN()]=1;
	for (int b=IN();b--;) vb[IN()]=1;
	For(i,1,n+1){
		V[va[i]][vb[i]].pb(i);
	}
	For(a,0,2) For(b,0,2){
		sort(V[a][b].begin(),V[a][b].end(),cmp);
		For(i,0,V[a][b].size()){
			s[a][b].pb((!i?0:s[a][b].back())+c[V[a][b][i]]);
		}
	}
	For(i,1,n+1) Modify(1,1,n,i,1);
	For(i,1,k+1){
		if (i<=V[1][0].size()){
			Modify(1,1,n,rnk[V[1][0][i-1]],0);
		}
		if (i<=V[0][1].size()){
			Modify(1,1,n,rnk[V[0][1][i-1]],0);
		}
	}
	For(i,0,m+1){
		cal(i);
		if (i>=V[1][1].size()) break;
		Modify(1,1,n,rnk[V[1][1][i]],0);
		if (k-i>0&&k-i<=V[1][0].size()) Modify(1,1,n,rnk[V[1][0][k-i-1]],1);
		if (k-i>0&&k-i<=V[0][1].size()) Modify(1,1,n,rnk[V[0][1][k-i-1]],1);
	}
	if (res==(1ll<<60)) res=-1;
	cout<<res<<endl;
}