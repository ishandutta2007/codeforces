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

const int N=300000+19;

vector<ll> V[4];
ll dp[4][N];
int n,m,x;

void Work(int x,int b,int L,int R,int l,int r){
	if (L>R) return;
	int mid=(L+R)/2,mx=0;
	For(i,l,r+1)
		if (i<=mid&&mid-i<V[x].size()){
			ll tmp=dp[x-1][i*x+b]+V[x][mid-i];
			if (tmp>dp[x][mid*x+b]){
				dp[x][mid*x+b]=tmp;
				mx=i;
			}
		}
	Work(x,b,L,mid-1,l,mx);
	Work(x,b,mid+1,R,mx,r);
}

int main(){
	n=IN(),m=IN();
	For(i,0,n){
		x=IN();
		V[x].pb(IN());
	}
	For(i,1,4){
		sort(V[i].begin(),V[i].end());
		V[i].pb(0);
		reverse(V[i].begin(),V[i].end());
		For(j,1,V[i].size()) V[i][j]+=V[i][j-1];
	}
	For(i,1,4){
		For(j,0,i){
			Work(i,j,0,(m-j)/i,0,(m-j)/i);
		}
	}
	cout<<dp[3][m]<<endl;
}