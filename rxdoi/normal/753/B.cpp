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

Vi V;
int x,y;

int main(){
	For(i,0,10){
		printf("%d%d%d%d\n",i,i,i,i);
		fflush(stdout);
		x=IN(),y=IN();
		if (x) V.pb(i);
	}
	do{
		For(i,0,V.size()) printf("%d",V[i]);
		puts("");
		fflush(stdout);
		x=IN(),y=IN();
		if (x==4) return 0;
	} while (next_permutation(V.begin(),V.end()));
}