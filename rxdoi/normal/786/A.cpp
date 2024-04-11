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

const int N=7000+19;

int vis[N][2],A[N][2],cnt[N][2],all[2];
int n;

void Renew(int y,int x,int val){
	vis[y][x]=val;
	if (val==0){
		For(i,1,n){
			if (A[i][x^1]&&vis[(y-i+n)%n][x^1]==-1){
				Renew((y-i+n)%n,x^1,1);
			}
		}
	} else{
		For(i,1,n){
			if (A[i][x^1]&&vis[(y-i+n)%n][x^1]==-1&&++cnt[(y-i+n)%n][x^1]==all[x^1]){
				Renew((y-i+n)%n,x^1,0);
			}
		}
	}
}

int main(){
	memset(vis,-1,sizeof(vis));
	n=IN();
	For(t,0,2){
		all[t]=IN();
		For(i,0,all[t]) A[IN()][t]=1;
	}
	vis[0][0]=0;
	vis[0][1]=0;
	Renew(0,0,0);
	Renew(0,1,0);
	For(t,0,2){
		For(i,1,n){
			printf("%s ",vis[i][t]==1?"Win":vis[i][t]==0?"Lose":"Loop");
		}
		puts("");
	}
}