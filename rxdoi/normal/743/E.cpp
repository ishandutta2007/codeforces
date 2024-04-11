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

int A[N],f[1<<8][N],sum[8][N];
int n,mx;

void Work(int s){
	memset(f,200,sizeof(f));
	For(i,0,n+1) f[0][i]=0;
	For(t,0,1<<8){
		For(j,0,8) if (t>>j&1){
			int k1=0,k2=0;
			For(i,1,n+1){
				while (k1<i&&sum[j][i]-sum[j][k1+1]>=s) k1++;
				while (k2<i&&sum[j][i]-sum[j][k2+1]>=s+1) k2++;
				if (sum[j][i]-sum[j][k1]>=s){
					f[t][i]=max(f[t][i],f[t^(1<<j)][k1]+s);
				}
				if (sum[j][i]-sum[j][k2]>=s+1){
					f[t][i]=max(f[t][i],f[t^(1<<j)][k2]+s+1);
				}
			}
		}
	}
	if (s==0){
		For(t,0,1<<8) mx=max(mx,f[t][n]);
	} else{
		mx=max(mx,f[(1<<8)-1][n]);
	}
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN()-1;
	For(i,0,8){
		For(j,1,n+1) sum[i][j]=sum[i][j-1]+(A[j]==i);
	}
	for (int t=0;8*t<=n;t++) Work(t);
	printf("%d\n",mx);
}