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

const int N=100+19,M=1000+19;
const db eps=1e-9;

db f[N][N*M],res;
int x[N];
int n,m,sum;

void U(int i,int l,int r,db v){
	f[i][l]+=v;
	f[i][r+1]-=v;
}

int main(){
	n=IN(),m=IN();
	if (m==1){
		printf("%.20lf\n",1.0);
		return 0;
	}
	For(i,1,n+1){
		x[i]=IN();
		sum+=x[i];
	}
	f[1][0]=1;
	For(i,1,n+1){
		For(j,0,sum){
			U(i+1,j+1,j+x[i]-1,f[i][j]/(m-1));
			U(i+1,j+x[i]+1,j+m,f[i][j]/(m-1));
		}
		For(j,1,sum) f[i+1][j]+=f[i+1][j-1];
	}
	For(j,0,sum) res+=f[n+1][j];
	printf("%.20lf\n",res*(m-1)+1);
}