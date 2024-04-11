#include<cstdio>
#include<cctype>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1e5+19;
vector<int> V[N];
int c[N],v[N];
int n,m,x,y,Ans=-1,cnt,res;

int main()
{
	n=IN(),m=IN();
	For(i,1,n+1) c[i]=IN(),v[c[i]]=1;
	For(i,0,m) x=IN(),y=IN(),V[c[x]].push_back(c[y]),V[c[y]].push_back(c[x]);
	For(i,1,1e5+1)
		if (v[i])
		{
			sort(V[i].begin(),V[i].end());cnt=0;
			For(j,0,V[i].size())
				if ((!j||V[i][j]!=V[i][j-1])&&V[i][j]!=i) cnt++;
			if (cnt>Ans) Ans=cnt,res=i;
		}
	printf("%d\n",res);
}