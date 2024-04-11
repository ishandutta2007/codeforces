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
typedef pair<int,ll> pil;
typedef vector<int> Vi;

const int N=2000+19;

pil v1[N][N],v2[N][N],v3[N][N],v4[N][N];
int x[N],y[N],vis[N];
int n,m,k,px,py,a,b,c,d,val;
char s[10];
ll sum[N],res;

int main(){
	n=IN(),m=IN(),k=IN();
	For(t,1,k+1){
		vis[t]=1;
		c=IN();
		For(i,1,c+1){
			x[t]=IN();y[t]=IN();
			val=IN();
			if (i>1){
				if (x[t]==px){
					if (y[t]>py){
						v1[x[t]][y[t]]=mp(t,sum[t]);
					} else{
						v2[x[t]][y[t]+1]=mp(t,sum[t]);
					}
				} else{
					if (x[t]>px){
						v3[x[t]][y[t]]=mp(t,sum[t]);
					} else{
						v4[x[t]+1][y[t]]=mp(t,sum[t]);
					}
				}
			}
			px=x[t],py=y[t];
			sum[t]+=val;
		}
	}
	for (int Qc=IN();Qc--;){
		scanf("%s",s);
		if (s[0]=='S'){
			vis[IN()]^=1;
		} else{
			a=IN(),c=IN(),b=IN(),d=IN();
			res=0;
			For(i,1,k+1)
				if (vis[i]){
					if (a<=x[i]&&x[i]<=b&&c<=y[i]&&y[i]<=d) res+=sum[i];
				}
			For(i,a,b+1){
				if (vis[v1[i][c].fi]) res-=v1[i][c].se;
				if (vis[v2[i][c].fi]) res+=v2[i][c].se;
				if (vis[v1[i][d+1].fi]) res+=v1[i][d+1].se;
				if (vis[v2[i][d+1].fi]) res-=v2[i][d+1].se;
			}
			For(i,c,d+1){
				if (vis[v3[a][i].fi]) res-=v3[a][i].se;
				if (vis[v4[a][i].fi]) res+=v4[a][i].se;
				if (vis[v3[b+1][i].fi]) res+=v3[b+1][i].se;
				if (vis[v4[b+1][i].fi]) res-=v4[b+1][i].se;
			}
			printf("%I64d\n",res);
		}
	}
}