#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=100+19;

pii A[N],B[N];
set<int> S[N],T[N],V;
int n,m,wei;

int cal(pii A,pii B){
	if (A.fi>A.se) swap(A.fi,A.se);
	if (B.fi>B.se) swap(B.fi,B.se);
	if (A==B) return -1;
	if (A.fi==B.fi) return A.fi;
	if (A.fi==B.se) return A.fi;
	if (A.se==B.fi) return A.se;
	if (A.se==B.se) return A.se;
	return -1;
}

int main(){
	n=IN(),m=IN();
	For(i,0,n) A[i]=mp(IN(),IN());
	For(i,0,m) B[i]=mp(IN(),IN());
	For(i,0,n) For(j,0,m){
		int x=cal(A[i],B[j]);
		if (x!=-1){
			S[i].insert(x);
			T[j].insert(x);
			V.insert(x);
		}
	}
	if (V.size()==1){
		printf("%d\n",*V.begin());
		return 0;
	}
	For(i,0,n) if (S[i].size()>1) wei=1;
	For(i,0,m) if (T[i].size()>1) wei=1;
	printf("%d\n",wei?-1:0);
}