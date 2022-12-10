#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2000+19;
const int oo=(1<<30)-1;

bitset<N> f,g;
int C,n;
Vi V;

int main(){
	C=IN(),n=IN();
	For(i,1,n+1) V.pb(IN()-C);
	sort(V.begin(),V.end());
	V.resize(unique(V.begin(),V.end())-V.begin());
	for (int i:V)
		if (i==0){
			puts("1");
			return 0;
		}
	f[1000]=1;
	For(t,1,1000+1){
		g.reset();
		for (int i:V){
			if (i>0) g|=f<<i;else g|=f>>-i;
		}
		f=g;
		if (f[1000]==1){
			printf("%d\n",t);
			return 0;
		}
	}
	puts("-1");
}