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

const int N=1000+19;
const int oo=(1<<30)-1;

int tmp[N][10][2];
int n;
Vi V;

int main(){
	memset(tmp,60,sizeof(tmp));
	n=IN();
	For(t,0,10)
		For(x,0,2){
			V.clear();
			For(i,1,n+1){
				if ((i>>t&1)==x) V.pb(i);
			}
			if (!V.size()) continue;
			printf("%d\n",V.size());
			For(i,0,V.size()) printf("%d ",V[i]);
			puts("");
			fflush(stdout);
			For(i,1,n+1) tmp[i][t][x]=IN();
		}
	puts("-1");
	For(i,1,n+1){
		int res=oo;
		For(t,0,10) res=min(res,tmp[i][t][i>>t&1^1]);
		printf("%d ",res);
	}
	fflush(stdout);
}