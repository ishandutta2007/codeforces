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

int n;
vector<Vi> V;

void gao(Vi A){
	V.pb(A);
}

int main(){
	n=IN();
	if (n%2==1){
		gao({1,2,3});
		gao({1,2,3});
		for (int i=4;i<=n;i+=2){
			gao({i,i+1,1});
			gao({i,i+1,1});
			for (int j=2;j<i;j+=2){
				gao({i,j,i+1,j+1});
				gao({i,j,i+1,j+1});
			}
		}
	} else{
		gao({1,2,3});
		gao({1,2,4});
		gao({1,3,4});
		gao({2,3,4});
		for (int i=5;i<=n;i+=2){
			gao({i,i+1,1});
			gao({i,i+1,2});
			gao({1,i,2,i+1});
			for (int j=3;j<i;j+=2){
				gao({i,j,i+1,j+1});
				gao({i,j,i+1,j+1});
			}
		}
	}
	printf("%d\n",V.size());
	for (Vi A:V){
		printf("%d ",A.size());
		for (int i:A) printf("%d ",i);
		puts("");
	}
}