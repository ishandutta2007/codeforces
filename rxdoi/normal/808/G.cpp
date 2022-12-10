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

const int N=100000+19;

char s[N],t[N];
int trs[N][26],Fail[N],dp[2][N],vis[N];
int n,m,tot,c,res,x;

void Upd(int &x,int y){
	if (y>x) x=y;
}
void Build(){
	static int Q[N];
	int f=1,w=0;Q[1]=0;
	while (f>w){
		int x=Q[++w];
		For(i,0,26){
			int &u=trs[x][i];
			if (u){
				Q[++f]=u;
				Fail[u]=(!x?0:trs[Fail[x]][i]);
			} else{
				u=trs[Fail[x]][i];
			}
		}
	}
}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	For(i,1,m+1){
		int &u=trs[x][t[i]-'a'];
		if (!u) u=++tot;x=u;
	}
	vis[x]=1;
	Build();
	memset(dp,200,sizeof(dp));
	dp[c][0]=0;
	For(i,1,n+1){
		memset(dp[c^1],200,sizeof(int)*(tot+1));
		For(j,0,tot+1)
			if (dp[c][j]>=0){
				For(k,0,26)
					if (s[i]=='?'||s[i]==k+'a'){
						Upd(dp[c^1][trs[j][k]],dp[c][j]+vis[trs[j][k]]);
					}
			}
		c^=1;
	}
	For(j,0,tot+1) Upd(res,dp[c][j]);
	printf("%d\n",res);
}