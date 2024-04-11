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
#define Rep(i,x,y) for (int i=x;i<=y;i++)
#define Dep(i,x,y) for (int i=x;i>=y;i--)
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

const int N=2000+19;
const int p=1e9+7;

char t[2][N],s[N];
int pre[2][N][N],suf[2][N][N];
int lcp[2][N][N],lcs[2][N][N];
int n,m,ans;

void Init(){
	For(i,0,2){
		Dep(j,n,1) Dep(k,m,1) lcp[i][j][k]=(t[i][j]==s[k]?lcp[i][j+1][k+1]+1:0);
		Rep(j,1,n) Dep(k,m,1) lcs[i][j][k]=(t[i][j]==s[k]?lcs[i][j-1][k+1]+1:0);
	}
}
void U(int &x,int y){
	x=(x+y)%p;
}
void Dp(){
	Rep(j,1,n) Rep(k,1,m) For(i,0,2){
		if (t[i][j]!=s[k]) continue;
		if (k==m){
			pre[i][j][k]=1;continue;
		}
		U(pre[i][j][k],pre[i][j-1][k+1]);
		if ((m-k+1)%2==0){
			int len=(m-k+1)/2;
			if (len<=j&&lcs[i][j][k]>=len&&lcp[i^1][j-len+1][k+len]>=len) U(pre[i][j][k],1);
		}
		if (t[i^1][j]==s[k+1]&&k+2<=m) U(pre[i][j][k],pre[i^1][j-1][k+2]);
	}
	Dep(j,n,1) Rep(k,1,m) For(i,0,2){
		if (t[i][j]!=s[k]) continue;
		if (k==m){
			suf[i][j][k]=1;continue;
		}
		U(suf[i][j][k],suf[i][j+1][k+1]);
		if ((m-k+1)%2==0){
			int len=(m-k+1)/2;
			if (len<=n-j+1&&lcp[i][j][k]>=len&&lcs[i^1][j+len-1][k+len]>=len) U(suf[i][j][k],1);
		}
		if (t[i^1][j]==s[k+1]&&k+2<=m) U(suf[i][j][k],suf[i^1][j+1][k+2]);
	}
}
void Work(){
	For(i,0,2) Rep(j,1,n){
		For(k,1,j){
			if (lcs[i][j][1]<j-k+1) continue;
			if (j-k+1==m){
				U(ans,1);
				continue;
			}
			if (t[i^1][k]!=s[j-k+2]) continue;
			if (j-k+2==m){
				U(ans,1);
				continue;
			}
			U(ans,pre[i^1][k-1][j-k+3]);
			int tmp=lcp[i^1][k][j-k+2];
			if (tmp<=j-k+1){
				if (tmp>=m-(j-k+1)) U(ans,1);
			} else{
				U(ans,suf[i^1][j+1][(j-k+1)*2+1]);
			}
		}
		Rep(k,j,n){
			if (lcp[i][j][1]<k-j+1) continue;
			if (k-j+1==m){
				U(ans,1);
				continue;
			}
			if (t[i^1][k]!=s[k-j+2]) continue;
			if (k-j+2==m){
				U(ans,1);
				continue;
			}
			U(ans,suf[i^1][k+1][k-j+3]);
			int tmp=lcs[i^1][k][k-j+2];
			if (tmp<=k-j+1){
				if (tmp>=m-(k-j+1)) U(ans,1);
			} else{
				U(ans,pre[i^1][j-1][(k-j+1)*2+1]);
			}
		}
	}
}

int main(){
	scanf("%s%s",t[0]+1,t[1]+1);
	n=strlen(t[0]+1);
	scanf("%s",s+1);
	m=strlen(s+1);
	Init();
	Dp();
	Work();
	printf("%d\n",ans);
}