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
const int p=1e9+9;

set<int> S;
map<pii,int> T;
pii A[N],B;
int n,c,res,x,y;

int Query(pii A){
	int res=0;
	if (T.count(mp(A.fi-1,A.se-1))) res++;
	if (T.count(mp(A.fi,A.se-1))) res++;
	if (T.count(mp(A.fi+1,A.se-1))) res++;
	return res;
}
bool check(pii A){
	if (T.count(mp(A.fi-1,A.se+1))&&Query(mp(A.fi-1,A.se+1))==1) return 0;
	if (T.count(mp(A.fi,A.se+1))&&Query(mp(A.fi,A.se+1))==1) return 0;
	if (T.count(mp(A.fi+1,A.se+1))&&Query(mp(A.fi+1,A.se+1))==1) return 0;
	return 1;
}

int main(){
	n=IN();
	For(i,1,n+1){
		x=IN(),y=IN();
		T[A[i]=mp(x,y)]=i;
	}
	for (map<pii,int>::iterator i=T.begin();i!=T.end();i++)
		if (check(i->fi)){
			S.insert(i->se);
		}
	while (!T.empty()){
		c++;
		int x=(c&1?*--S.end():*S.begin());
		S.erase(x);
		T.erase(A[x]);
		for (int a=-2;a<=2;a++)
			for (int b=-2;b<=2;b++)
				if (abs(a)+abs(b)<=2){
					B=mp(A[x].fi+a,A[x].se+b);
					if (T.count(B)){
						if (S.find(T[B])!=S.end()&&!check(B)) S.erase(T[B]);else
						if (S.find(T[B])==S.end()&&check(B)) S.insert(T[B]);
					}
				}
		res=(1ll*res*n+x-1)%p;
	}
	printf("%d\n",res);
}