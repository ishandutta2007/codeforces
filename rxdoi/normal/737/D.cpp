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
	int c,F,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(F=1,x=0):(F=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !F?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=4000+19;
const int M=90;
const int oo=(1<<30)-1;

int f[N][M*2][M];
int S[N];
int n;

int F(int l,int r,int k){
	if (f[l][r][k]!=oo) return f[l][r][k];
	int &res=f[l][r][k];
	r=r-M+l;
	res=-oo;
	for (int i=k;i<=k+1;i++)
		if (l+r+i<=n){
			int tmp=oo;
			for (int j=i;j<=i+1;j++)
				if (l+r+i+j<=n){
					tmp=min(tmp,F(l+i,r-l+j-i+M,j)-(S[n-r]-S[n-r-j]));
				}
			if (tmp==oo) tmp=0;
			res=max(res,tmp+S[l+i]-S[l]);
		}
	if (res==-oo) res=0;
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1) S[i]=S[i-1]+IN();
	For(i,0,N) For(j,0,M*2) For(k,0,M) f[i][j][k]=oo;
	printf("%d\n",F(0,M,1));
}