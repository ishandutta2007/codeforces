#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

int n;
int A,B;
int SA[1001000][2];
int SB[1001000][2];
int ass[1001];
int E[2001][2001];
int G[2001][2001];
int belong[2001];
int dfn[2001];
int low[2001];
bool vis[2001];
bool in[2001];
int now;
int la;
stack<int> S;
vector<int> Rec[2001];
bitset<2001> F[2001];

bool MT[2001];
bool MF[2001];

int Q[5001][2];
int QH,QT;

inline void setMT(int x){
	if(MT[x]) return;
	MT[x]=1;
	QT=-1;
	Q[++QT][0]=x;
	Q[QT][1]=1;
	for(int i=0;i<=QT;++i){
		int x=Q[i][0];
		int v=Q[i][1];
		for(int j=0;j<int(Rec[x].size());++j){
			if(v==1){
				if(!MF[belong[Rec[x][j]^1]]){
					MF[belong[Rec[x][j]^1]]=1;
					Q[++QT][0]=belong[Rec[x][j]^1];
					Q[QT][1]=0;
				}
			}
			else{
				if(!MT[belong[Rec[x][j]^1]]){
					MT[belong[Rec[x][j]^1]]=1;
					Q[++QT][0]=belong[Rec[x][j]^1];
					Q[QT][1]=1;
				}
			}
		}
		if(v==1){
			for(int j=0;j<la;++j) if(F[x][j]&&!MT[j]){
				MT[j]=1;
				Q[++QT][0]=j;
				Q[QT][1]=1;
			}
		}
		else if(v==0){
			for(int j=0;j<la;++j) if(F[j][x]&&!MF[j]){
				MF[j]=1;
				Q[++QT][0]=j;
				Q[QT][1]=0;
			}
		}
	}
}

void tarjan(int x){
	dfn[x]=low[x]=++now;
	vis[x]=1,in[x]=1;
	S.push(x);
	for(int i=0;i<2*n;++i)if(E[x][i]){
		if(!vis[i]){
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else if(in[i]){
			low[x]=min(low[x],dfn[i]);
		}
	}
	if(low[x]==dfn[x]){
		int f=-1;
		Rec[la].clear();
		do{
			f=S.top();
			S.pop();
			belong[f]=la;
			in[f]=0;
			Rec[la].push_back(f);
		}while(f!=x);
		la++;
	}
}

bool solve(int S[1001000][2],int N,int T[1001000][2],int M){
	for(int i=0;i<2*n;++i){
		for(int j=0;j<2*n;++j){
			E[i][j]=0;
		}
		vis[i]=0;
	}
	for(int i=1;i<=N;++i){
		int x=S[i][0],y=S[i][1];
		if(x<0) x=(-x)*2-2;
		else x=x*2-1;
		if(y<0) y=(-y)*2-2;
		else y=y*2-1;
		E[x^1][y]=1;
		E[y^1][x]=1;
	}
	la=now=0;
	for(int i=0;i<2*n;++i) if(!vis[i]){
		tarjan(i);
	}
	for(int i=0;i<n;++i){
		if(belong[2*i]==belong[2*i+1]) return false;
	}
	for(int i=0;i<la;++i) for(int j=0;j<la;++j) G[i][j]=0;
	for(int i=0;i<2*n;++i) for(int j=0;j<2*n;++j) if(E[i][j]&&belong[i]!=belong[j]){
		G[belong[i]][belong[j]]=1;
	}
	for(int i=0;i<la;++i){
		F[i].reset();
		F[i][i]=1;
		MT[i]=false;
		MF[i]=false;
		for(int j=0;j<la;++j) if(G[i][j]){
			F[i]|=F[j];
		}
	}
	for(int i=0;i<n;++i){
		if(F[belong[2*i]][belong[2*i+1]]) setMT(belong[2*i+1]);
		else if(F[belong[2*i+1]][belong[2*i]]) setMT(belong[2*i]);
	}
	for(int i=1;i<=M;++i){
		int x=T[i][0],y=T[i][1];
		if(x<0) x=(-x)*2-2;
		else x=x*2-1;
		if(y<0) y=(-y)*2-2;
		else y=y*2-1;
		x^=1,y^=1;
		if(F[belong[x]][belong[y^1]]) continue;
		if(F[belong[y]][belong[x^1]]) continue;
		if(MF[belong[x]]) continue;
		if(MF[belong[y]]) continue;
		setMT(belong[x]);
		setMT(belong[y]);
		for(int j=0;j<la;++j){
			if(!MT[j]&&!MF[j]){
				setMT(j);
			}
		}
		for(int j=0;j<n;++j){
			if(MT[belong[j*2]]) ass[j+1]=0;
			else ass[j+1]=1;
		}
		return true;
	}
	return false;
}

int main(){
	scanf("%d%d%d",&n,&A,&B);
	REP_1(i,A){
		scanf("%d%d",SA[i],SA[i]+1);
	}
	REP_1(i,B){
		scanf("%d%d",SB[i],SB[i]+1);
	}
	if(solve(SA,A,SB,B)||solve(SB,B,SA,A)){
		for(int i=1;i<=n;++i) printf("%d%c",ass[i],i==n?'\n':' ');
	}
	else{
		printf("SIMILAR\n");
	}
	cin>>n;
	return 0;
}