#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define SET(v,x) memset(v,x,sizeof(v))
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int(v.size())
#define SI ({int x;scanf("%d",&x);x;})

int n,k,m;
char b[522][522];
char g[5][5];
int p[6];

void fillit(int x1,int y1,int x2,int y2,char c)
{
	for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
		b[i][j] = c;
}

void go(int x1,int y1,int s)
{
	if(s==1)
	{
		for(int i=0;i<n;i++) for(int j=0;j<n;j++)
			b[x1+i][y1+j] = g[i][j];
		return;
	}

	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		if(g[i][j]=='*') fillit(x1+i*p[s-1],y1+j*p[s-1],x1+(i+1)*p[s-1]-1,y1+(j+1)*p[s-1]-1,'*');
		else go(x1+i*p[s-1],y1+j*p[s-1],s-1);	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j;
	n=SI; k=SI;
	for(i=0;i<n;i++) scanf(" %s",g[i]);
	
	p[0]=1;
	for(m=1,i=1;i<=k;i++){ m*=n; p[i]=m; }
	fillit(0,0,m-1,m-1,'.');
	go(0,0,k);

	for(i=0;i<m;i++,puts(""))
		for(j=0;j<m;j++) printf("%c",b[i][j]);

	return 0;
}