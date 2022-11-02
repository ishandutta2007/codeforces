#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int bigp=1000000007;

int main()
{
	int N,M,X;
	scanf("%d %d %d",&N,&M,&X);
	if (N>M)
	{
		printf("0\n");
		return 0;
	}
	int f[N+1][2][N+1],x1,x2;
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	for (int j=0;j<M;j++)
	{
		x1=j%2,x2=1-j%2;
		for (int i=0;i<=N;i++)
			for (int k=0;k<=N;k++)
				f[i][x2][k]=0;
		for (int i=0;i<=N;i++)
			for (int k=0;k<=N;k++)
				if (f[i][x1][k]!=0)
				{
					// open+close
					if (i<N)
						f[i+1][x2][k]=(f[i+1][x2][k]+f[i][x1][k])%bigp;
					// open+not close
					if ((i<N)&&(k<N))
						f[i+1][x2][k+1]=(f[i+1][x2][k+1]+f[i][x1][k])%bigp;
					// not open+close
					if ((j+1!=X)&&(k>0))
						f[i][x2][k-1]=(f[i][x2][k-1]+f[i][x1][k])%bigp;
					// not open+not close
					if (j+1!=X)
						f[i][x2][k]=(f[i][x2][k]+f[i][x1][k])%bigp;
				}
	}
	int fac=1;
	for (int i=1;i<=N;i++) fac=(LL)fac*i%bigp;
	printf("%d\n",(LL)f[N][x2][0]*fac%bigp);

    return 0;
}