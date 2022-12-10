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

const int p=1e9+7;
const int N=40;

int t[N],dp[N][N][2],C[N][N];
int n,c,res;

void Upd(int &x,ll y){
	x=(x+y)%p;
}
void Work(){
	for (;n;n/=2) t[++c]=n%2;
	dp[N-1][0][0]=1;
	for (int i=N-1;i;i--)
		For(j,0,N) For(k,0,2)
			if (dp[i][j][k]){
				if (k||t[i]){
					Upd(dp[i-1][j+1][k],dp[i][j][k]);
				}
				For(s,0,2) if (k||s<=t[i]){
					For(x,0,j+1) if (x%2==s){
						Upd(dp[i-1][j][k||s<t[i]],1ll*dp[i][j][k]*C[j][x]);
					}
				}
			}
	For(j,0,N) For(k,0,2) res=(res+dp[0][j][k])%p;
}

int main(){
	For(i,0,N){
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	n=IN();
	Work();
	printf("%d\n",res);
}