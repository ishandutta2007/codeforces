#include<set>
#include<map>
#include<ctime>
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

const int N=100000+19;
const int M=330;
const int oo=(1<<30)-1;

struct QType{
	int l,r,id;
	bool operator < (const QType &B) const {return r<B.r;}
};
vector<QType> V[M];
int A[N],B[N],C[N],res[3*N],Q[N],tmp[N],pre[N],suf[N],pre2[N],suf2[N],s[N],t[N],vis[N];
int cnt[M],pre3[N][M],suf3[N][M];
int n,q,l,r,top,now,c,H;

void Sort(int l,int r){
	memset(cnt,0,sizeof(cnt));
	For(i,l,r+1) cnt[C[i]%M]++;
	For(i,1,M) cnt[i]+=cnt[i-1];
	for (int i=r;i>=l;i--) tmp[cnt[C[i]%M]--]=i;
	memset(cnt,0,sizeof(cnt));
	For(i,l,r+1) cnt[C[i]/M]++;
	For(i,1,M) cnt[i]+=cnt[i-1];
	for (int i=r-l+1;i;i--) Q[cnt[C[tmp[i]]/M]--]=tmp[i];
	*Q=r-l+1;
}
void Work(int id,int l,int r){
	if (V[id].empty()) return;
	memset(vis,0,sizeof(vis));
	for (QType Q:V[id]) vis[Q.r]=1;
	
	Sort(r+1,n-1);
	For(i,1,*Q+1){
		pre[Q[i]]=Q[i-1];
		suf[Q[i]]=Q[i+1];
	}
	pre[Q[1]]=suf[Q[*Q]]=-1;
	for (int i=n-1;i>r;i--){
		pre2[i]=pre[i];
		suf2[i]=suf[i];
		if (~suf[i]) pre[suf[i]]=pre[i];
		if (~pre[i]) suf[pre[i]]=suf[i];
	}
	
	Sort(l,n-1);
	For(i,1,*Q+1){
		pre[Q[i]]=Q[i-1];
		suf[Q[i]]=Q[i+1];
	}
	pre[Q[1]]=suf[Q[*Q]]=-1;
	for (int i=n-1;i>r;i--){
		if (vis[i]){
			for (int j=l;j<=r;j++){
				pre3[i][j-l]=pre[j];
				suf3[i][j-l]=suf[j];
				if (~suf[j]){
					top++;s[top]=suf[j]+1;t[top]=pre[suf[j]];
					pre[suf[j]]=pre[j];
				}
				if (~pre[j]){
					top++;s[top]=-pre[j]-1;t[top]=suf[pre[j]];
					suf[pre[j]]=suf[j];
				}
			}
			for (;top;top--){
				int x=s[top],y=t[top];
				if (x>0) pre[x-1]=y;else suf[-x-1]=y;
			}
		}
		if (~suf[i]) pre[suf[i]]=pre[i];
		if (~pre[i]) suf[pre[i]]=suf[i];
	}
	
	sort(V[id].begin(),V[id].end());
	now=oo;c=r+1;
	for (QType Q:V[id]){
		for (;c<=Q.r;c++){
			if (~pre2[c]) now=min(now,A[c]-A[pre2[c]]);
			if (~suf2[c]) now=min(now,A[suf2[c]]-A[c]);
		}
		int tmp=now;
		for (int i=r;i>=Q.l;i--){
			if (~pre3[c-1][i-l]) tmp=min(tmp,A[i]-A[pre3[c-1][i-l]]);
			if (~suf3[c-1][i-l]) tmp=min(tmp,A[suf3[c-1][i-l]]-A[i]);
		}
		res[Q.id]=tmp;
	}
}

int main(){
	n=IN();
	For(i,0,n){
		A[i]=B[i+1]=IN();
	}
	sort(B+1,B+n+1);
	*B=unique(B+1,B+n+1)-B-1;
	For(i,0,n){
		C[i]=lower_bound(B+1,B+*B+1,A[i])-B;
	}
	while (H*H<=n) H++;
	q=IN();
	For(t,0,q){
		l=IN()-1,r=IN()-1;
		if (l/H==r/H){
			Sort(l,r);
			res[t]=oo;
			For(i,2,r-l+2) res[t]=min(res[t],A[Q[i]]-A[Q[i-1]]);
		} else{
			V[l/H].pb((QType){l,r,t});
		}
	}
	for (int i=0;i<(n-1)/H;i++){
		Work(i,i*H,i*H+H-1);
	}
	For(i,0,q) printf("%d\n",res[i]);
}