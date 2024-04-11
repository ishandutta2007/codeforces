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

const int N=5000+19;

int P[N],B[N],P2[N],B2[N],res[N];
int n,ans;

int main(){
	n=IN();
	For(i,0,n){
		printf("? %d %d\n",i,0);
		fflush(stdout);
		P[i]=IN();
	}
	For(i,0,n){
		printf("? %d %d\n",0,i);
		fflush(stdout);
		B[i]=IN();
	}
	for (int i=n-1;~i;i--) B[i]^=B[0];
	For(w,0,n){
		For(i,0,n){
			P2[i]=P[i]^w;
			B2[i]=B[i]^w;
		}
		int chk=1;
		For(i,0,n){
			if (P2[i]>n||B2[i]>n) chk=0;
		}
		if (!chk) continue;
		For(i,0,n) if (P2[B2[i]]!=i) chk=0;
		if (!chk) continue;
		ans++;
		memcpy(res,P2,sizeof(P2));
	}
	printf("!\n");
	printf("%d\n",ans);
	For(i,0,n) printf("%d ",res[i]);
	puts("");
}