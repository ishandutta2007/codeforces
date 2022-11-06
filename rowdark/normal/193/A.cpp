#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#define MP make_pair

using namespace std;

const pair<int,int> D[4]={MP(0,1),MP(1,0),MP(0,-1),MP(-1,0)};

pair<int,int> operator +(const pair<int,int> A,const pair<int,int> B){
	return MP(A.first+B.first,A.second+B.second);
}

queue<pair<int,int> > Q;

pair<int,int> X,Y,S;

int Count,Found;

bool Visited[51][51];

bool CutPoint;

char A[51][51];

int N,M,Dfn[51][51],Low[51][51],Now;

void Updata(int &a,int b){
	if(b<a) a=b;
}

bool Dfs(pair<int,int> P,pair<int,int> Fa){
	Visited[P.first][P.second]=1;
	Dfn[P.first][P.second]=Low[P.first][P.second]=++Now;
	for(int i=0;i<4;++i)
	{
		pair<int,int> F=P+D[i];
		if(F.first==Fa.first&&F.second==Fa.second) continue;
		if(F.first>-1&&F.first<N&&F.second>-1&&F.second<M&&A[F.first][F.second]=='#')
		{
			if(!Visited[F.first][F.second])
			{
				if(!Dfs(F,P)) return 0;
				if(Dfn[P.first][P.second]<=Low[F.first][F.second]) return 0;
				Updata(Low[P.first][P.second],Low[F.first][F.second]);
			}
			else
			{
				Updata(Low[P.first][P.second],Low[F.first][F.second]);
			}
		}
	}
	return 1;
}

int Check(){
	memset(Visited,0,sizeof(Visited));
	bool Flag=0;
	Visited[S.first][S.second]=1;
	for(int i=0;i<2;++i)
	{
		Y=S+D[i];
		if(Y.first>-1&&Y.first<N&&Y.second>-1&&Y.second<M&&A[Y.first][Y.second]=='#'&&!Visited[Y.first][Y.second])
		{
			if(!Flag) Flag=1;
			else return 0;
			if(!Dfs(Y,S)) return 0;
		}
	}
	return 1;
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i)
	{
		scanf("%s",A[i]);
		for(int j=0;j<M;++j)
		{
			if(A[i][j]=='#')
			{
				++Count;
				if(Q.empty())
				{
					Q.push(S=MP(i,j));
					Visited[i][j]=1;
				}
			}
		}
	}
	if(Count<2)
	{
		puts("-1");
		return 0;
	}
	while(!Q.empty())
	{
		X=Q.front();
		Q.pop();
		++Found;
		Visited[X.first][X.second]=1;
		for(int i=0;i<4;++i)
		{
			Y=X+D[i];
			if(Y.first>-1&&Y.first<N&&Y.second>-1&&Y.second<M)
			{
				if(A[Y.first][Y.second]=='#'&&!Visited[Y.first][Y.second])
				{
					Q.push(Y);
					Visited[Y.first][Y.second]=1;
				}
			}
		}
	}
	if(Found!=Count)
	{
		puts("0");
		return 0;
	}
	if(Found==2)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",1+Check());
	scanf("%d",&N);
	return 0;
}