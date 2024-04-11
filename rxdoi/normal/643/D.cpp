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
#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;

multiset<ll> s[N],s1,s2;
ll B[N],plu[N],C[N];
int A[N],D[N];
int n,q;

void bao(int x){
	if (!s[x].empty()){
		s1.erase(s1.find(*s[x].begin()+plu[x]));
		s2.erase(s2.find(*--s[x].end()+plu[x]));
	}
}
void gao(int x){
	if (!s[x].empty()){
		s1.insert(*s[x].begin()+plu[x]);
		s2.insert(*--s[x].end()+plu[x]);
	}
}
void Remove(int x){
	bao(A[x]);
	s[A[x]].erase(s[A[x]].find(C[x]));
	gao(A[x]);
}
void Resume(int x){
	bao(A[x]);
	s[A[x]].insert(C[x]);
	gao(A[x]);
}
void Modify(int x,ll v){
	Remove(A[x]);
	C[A[x]]+=v;
	Resume(A[x]);
	Remove(x);
	C[x]+=v;
	Resume(x);
	if (s[x].size()){
		bao(x);
		plu[x]+=v;
		gao(x);
	}
}
void Cut(int x){
	Remove(x);
	C[x]+=plu[A[x]];
	Remove(A[x]);
	C[A[x]]-=B[x]/D[x];
	Resume(A[x]);
}
void Link(int x){
	C[x]-=plu[A[x]];
	Resume(x);
	Remove(A[x]);
	C[A[x]]+=B[x]/D[x];
	Resume(A[x]);
}

int main(){
	n=IN(),q=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1){
		A[i]=IN();
		D[i]+=2;
		D[A[i]]++;
	}
	For(i,1,n+1){
		C[i]+=B[i]%D[i]+B[i]/D[i]+B[A[i]]/D[A[i]];
		C[A[i]]+=B[i]/D[i];
	}
	For(i,1,n+1){
		s[A[i]].insert(C[i]);
	}
	For(i,1,n+1) if (s[i].size()){
		s1.insert(*s[i].begin());
		s2.insert(*--s[i].end());
	}
	while (q--){
		int o=IN();
		if (o==1){
			int i=IN();
			int x=A[i],y=IN();
			Modify(x,-B[x]/D[x]);
			Cut(i);
			Modify(x,B[x]/(D[x]-1));
			Remove(x);
			C[x]+=B[x]%(D[x]-1)-B[x]%D[x];
			D[x]--;
			Resume(x);
			A[i]=y;
			Modify(y,-B[y]/D[y]);
			Link(i);
			Modify(y,B[y]/(D[y]+1));
			Remove(y);
			C[y]+=B[y]%(D[y]+1)-B[y]%D[y];
			D[y]++;
			Resume(y);
		} lf (o==2){
			int i=IN();
			printf("%I64d\n",C[i]+plu[A[i]]);
		} lf (o==3){
			printf("%I64d %I64d\n",*s1.begin(),*--s2.end());
		}
	}
}