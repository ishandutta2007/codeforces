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

const int N=2000000+19;

int P[N],pool[4*N],*cnt=pool+2*N;
int n,cl,cr,plu,pos;
ll res=1ll<<60,tmp;

int main(){
	n=IN();
	For(i,1,n+1) P[i]=IN();
	For(i,1,n+1){
		cnt[P[i]-i]++;
		if (P[i]-i<0) cl++;else cr++;
		tmp+=abs(P[i]-i);
	}
	for (int i=n;i;i--){
		if (tmp<res) res=tmp,pos=n-i;
		cnt[P[i]-n-plu]--;
		tmp-=abs(P[i]-n);
		if (P[i]-n<0) cl--;else cr--;
		cl+=cnt[-plu];
		cr-=cnt[-plu];
		plu--;
		tmp+=cl;
		tmp-=cr;
		cnt[P[i]-1-plu]++;
		tmp+=abs(P[i]-1);
		if (P[i]-1<0) cl++;else cr++;
	}
	printf("%I64d %d\n",res,pos);
}