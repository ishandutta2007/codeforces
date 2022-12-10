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

const int N=1000+19;
const db eps=1e-8;

db F[N*10][N],pro[N*10];
int m,q,top,p;

int main(){
	m=IN(),q=IN();
	F[0][0]=1;
	for (int i=0;;i++){
		For(j,0,m+1){
			F[i+1][j]+=F[i][j]*(1.0*j/m);
			F[i+1][j+1]+=F[i][j]*(1-1.0*j/m);
		}
		pro[i]=F[i][m];
		if (pro[i]>0.51){
			top=i;
			break;
		}
	}
	while (q--){
		p=IN();
		printf("%d\n",lower_bound(pro+1,pro+top+1,(p-eps)/2000.0)-pro);
	}
}