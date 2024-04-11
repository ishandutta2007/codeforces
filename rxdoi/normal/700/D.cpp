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

const int N=100000+19;

priority_queue<int,vector<int>,greater<int> > T;
int A[N],c[N],d[N],cnt[N],B[N];
int S,n,Qc,l,r,mx;
ll res[N];

struct QType{
	int l,r,id;
	bool operator < (const QType &B) const{
		if (l/S!=B.l/S) return l/S<B.l/S;
		return r<B.r;
	}
} Q[N];

void Add(int x,int v){
	c[cnt[x]]--;
	cnt[x]+=v;
	c[cnt[x]]++;
}
ll work(){
	ll res=0,v=0;
	while (!T.empty()) T.pop();
	For(i,1,S+1) d[i]=c[i];
	For(i,1,S+1){
		if (d[i]&&v){
			res+=i+v;
			if (i+v<=S) d[i+v]++;else T.push(i+v);
			d[i]--,v=0;
		}
		res+=2*i*(d[i]/2);
		if (2*i<=S){
			d[2*i]+=d[i]/2;
		} else{
			For(j,0,d[i]/2) T.push(2*i);
		}
		if (d[i]%2==1) v=i;
	}
	if (v) T.push(v);
	For(i,1,*B+1){
		if (cnt[B[i]]>S) T.push(cnt[B[i]]);
	}
	while (T.size()!=1){
		ll a,b;
		a=T.top();T.pop();
		b=T.top();T.pop();
		T.push(a+b);
		res+=a+b;
	}
	return res;
}

int main(){
	n=IN();
	S=sqrt(n)+1;
	For(i,1,n+1){
		A[i]=IN();
		cnt[A[i]]++;
		mx=max(mx,A[i]);
	}
	Qc=IN();
	For(i,1,Qc+1) Q[i]=(QType){IN(),IN(),i};
	For(i,1,mx+1){
		if (cnt[i]>S) B[++*B]=i;
	}
	memset(cnt,0,sizeof(cnt));
	sort(Q+1,Q+Qc+1);
	l=1,r=1;Add(A[1],1);
	For(i,1,Qc+1){
		while (l>Q[i].l) Add(A[--l],1);
		while (l<Q[i].l) Add(A[l++],-1);
		while (r<Q[i].r) Add(A[++r],1);
		while (r>Q[i].r) Add(A[r--],-1);
		res[Q[i].id]=work();
	}
	For(i,1,Qc+1) printf("%d\n",res[i]);
}