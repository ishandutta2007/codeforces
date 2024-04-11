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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

int n;
vector<pii> res;

void work(int i,int j){
	if (i+1==j&&i%2==1&&n%4==1){
		res.pb(mp(i,n));
		res.pb(mp(i,j));
		res.pb(mp(j,n));
	} else{
		res.pb(mp(i,j));
	}
}

int main(){
	n=IN();
	if (n%4>1){
		puts("NO");
		return 0;
	}
	for (int i=0;i+4<=n;i+=4){
		work(i+1,i+2);
		work(i+1,i+3);
		work(i+2,i+4);
		work(i+1,i+4);
		work(i+2,i+3);
		work(i+3,i+4);
	}
	for (int i=0;i+4<=n;i+=4)
		for (int j=i+4;j+4<=n;j+=4){
			work(i+4,j+3);
			work(i+3,j+3);
			work(i+4,j+2);
			work(i+1,j+2);
			work(i+2,j+4);
			work(i+3,j+4);
			work(i+2,j+3);
			work(i+2,j+2);
			work(i+4,j+1);
			work(i+4,j+4);
			work(i+1,j+3);
			work(i+1,j+4);
			work(i+3,j+1);
			work(i+3,j+2);
			work(i+2,j+1);
			work(i+1,j+1);
		}
	puts("YES");
	for (pii i:res) printf("%d %d\n",i.fi,i.se);
}