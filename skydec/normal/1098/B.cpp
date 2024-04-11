#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=310000;
string a[N];
string bb[N];
int n,m;
int f[N];
int w[N][4][4];
int w1[N][4][4];
char t[4]={'A','C','G','T'};
int p[6];
int calc(){
	int ans=0;
	rep(j,0,m-1){
		if(j&1)
		ans+=min(w[j][p[0]][p[1]],w[j][p[1]][p[0]]);
		else ans+=min(w[j][p[2]][p[3]],w[j][p[3]][p[2]]);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	rep(i,0,n-1)cin>>a[i];
	rep(j,0,m-1)rep(x,0,3)rep(y,0,3)if(x!=y){
		rep(i,0,n-1)if(i&1)w[j][x][y]+=(t[y]!=a[i][j]);
		else w[j][x][y]+=(t[x]!=a[i][j]);
	}
	rep(i,0,3)p[i]=i;
	int ap[4];
	int wa=1e9;
	rep(tt,0,23){
		int w=calc();
		if(w<wa){
			wa=w;
			rep(i,0,3)ap[i]=p[i];
		}
		next_permutation(p,p+4);
	}
	rep(i,0,m-1)rep(x,0,3)rep(y,0,3)w1[i][x][y]=w[i][x][y];


	memset(w,0,sizeof w);
	rep(i,0,n-1)bb[i]=a[i],a[i]="";
	rep(i,0,n-1)rep(j,0,m-1)a[j]+=bb[i][j];
	swap(n,m);

	rep(j,0,m-1)rep(x,0,3)rep(y,0,3)if(x!=y){
		rep(i,0,n-1)if(i&1)w[j][x][y]+=(t[y]!=a[i][j]);
		else w[j][x][y]+=(t[x]!=a[i][j]);
	}
	rep(i,0,3)p[i]=i;
	int bp[4];
	int ba=1e9;
	rep(tt,0,23){
		int w=calc();
		if(w<ba){
			ba=w;
			rep(i,0,3)bp[i]=p[i];
		}
		next_permutation(p,p+4);
	}

	swap(n,m);

	if(wa<ba){
		//printf("%d\n",wa);
		rep(i,0,n-1)rep(j,0,m-1){
			char s[2];
			if(j&1){
				if(w1[j][ap[0]][ap[1]]<w1[j][ap[1]][ap[0]]){
					s[0]=t[ap[0]];
					s[1]=t[ap[1]];
				}
				else{
					s[0]=t[ap[1]];
					s[1]=t[ap[0]];
				}
			}
			else{
				if(w1[j][ap[2]][ap[3]]<w1[j][ap[3]][ap[2]]){
					s[0]=t[ap[2]];
					s[1]=t[ap[3]];
				}
				else{
					s[0]=t[ap[3]];
					s[1]=t[ap[2]];
				}
			}
			printf("%c",s[i&1]);
			if(j==m-1)puts("");
		}
	}
	else{
		//printf("%d\n",ba);
		rep(i,0,n-1)rep(j,0,m-1){
			char s[2];
			if(i&1){
				if(w[i][bp[0]][bp[1]]<w[i][bp[1]][bp[0]]){
					s[0]=t[bp[0]];
					s[1]=t[bp[1]];
				}
				else{
					s[0]=t[bp[1]];
					s[1]=t[bp[0]];
				}
			}
			else{
				if(w[i][bp[2]][bp[3]]<w[i][bp[3]][bp[2]]){
					s[0]=t[bp[2]];
					s[1]=t[bp[3]];
				}
				else{
					s[0]=t[bp[3]];
					s[1]=t[bp[2]];
				}
			}
			printf("%c",s[j&1]);
			if(j==m-1)puts("");
		}
	}

	return 0;
}