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

const int N=100+19;

int A[N],f[N][3];
int n,res=(1<<30)-1;

void U(int &x,int y){
	x=min(x,y);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	memset(f,60,sizeof(f));
	f[0][0]=0;
	For(i,1,n+1){
		For(j,0,3){
			U(f[i][0],f[i-1][j]+1);
			For(k,1,3)
				if ((A[i]&k)&&k!=j){
					U(f[i][k],f[i-1][j]);
				}
		}
	}
	For(i,0,3) U(res,f[n][i]);
	printf("%d\n",res);
}