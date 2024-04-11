#include<map>
#include<cstdio>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define mp make_pair
using namespace std;

const int N=26;
typedef long long LL;
int n,K,A[N];
LL S,Fac[N],Ans;
map<pair<int,LL>,int> M1,M2;

void DFS_1(int x,int k,LL s)
{
	if (k>K||s>S) return;
	if (x==n/2) {M1[mp(k,s)]++;return;}
	DFS_1(x+1,k,s);
	DFS_1(x+1,k,s+A[x]);
	if (A[x]<20) DFS_1(x+1,k+1,s+Fac[A[x]]);
}
void DFS_2(int x,int k,LL s)
{
	if (k>K||s>S) return;
	if (x==n) {M2[mp(k,s)]++;return;}
	DFS_2(x+1,k,s);
	DFS_2(x+1,k,s+A[x]);
	if (A[x]<20) DFS_2(x+1,k+1,s+Fac[A[x]]);
}

int main()
{
	scanf("%d%d%I64d",&n,&K,&S);
	Fac[0]=1;For(i,1,20) Fac[i]=Fac[i-1]*i;
	For(i,0,n) scanf("%d",&A[i]);
	random_shuffle(A,A+n);
	DFS_1(0,0,0);
	DFS_2(n/2,0,0);
	for (map<pair<int,LL>,int>::iterator it=M1.begin();it!=M1.end();it++)
	{
		int k=(*it).first.first;LL s=(*it).first.second;
		For(i,0,K-k+1) Ans+=1LL*(*it).second*M2[mp(i,S-s)];
	}
	printf("%I64d\n",Ans);
}