#include<cstdio>
#include<cctype>
#include<vector>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100000+19;
typedef long long LL;
LL A[N];int S,k,t;
vector<int> V;

int main()
{
	S=IN(),k=IN();
	A[0]=A[1]=1;
	for (t=2;A[t-1]<=S;t++)
		For(i,max(t-k,0),t) A[t]+=A[i];
	for (int i=t;i;i--) if (A[i]<=S) S-=A[i],V.Pb(A[i]);
	printf("%d\n",V.size());
	For(i,0,V.size()) printf("%d ",V[i]);
}