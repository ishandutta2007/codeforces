#include<cstdio>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Fir first
#define Sec second
#define mp make_pair
using namespace std;

int k,T,x,S1,S2;
typedef pair<int,int> PII;
vector<PII> V;

void Link(int x,int y) {V.push_back(mp(x,y));}
int Graph()
{
	x=++T,S1=++T,S2=++T;
	Link(S1,S2);
	For(i,1,k) T++,Link(x,T),Link(S1,T),Link(S2,T);
	For(i,1,k) For(j,i+2,k)
		if (j!=i+1&&!(i==1&&j==k-1)) Link(S2+i,S2+j);
	if (k!=3) For(i,1,k) if (i&1) Link(S2+i,S2+i+1);
	return x;
}

int main()
{
	scanf("%d",&k);
	if (k%2==0) return puts("NO"),0;
	puts("YES");
	if (k==1) return puts("2 1"),puts("1 2"),0;
	V.push_back(mp(Graph(),Graph()));
	printf("%d %d\n",T,V.size());
	For(i,0,V.size()) printf("%d %d\n",V[i].Fir,V[i].Sec);
}