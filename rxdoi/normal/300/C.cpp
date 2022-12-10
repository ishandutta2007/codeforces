#include<cstdio>
#include<vector>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int P=1e9+7,N=1e6+19;
vector<int> V;
int Fac[N],a,b,n,Ans;

int Pow(int a,int b)
{
	int res=1;
	for (;b;b>>=1,a=1LL*a*a%P) if (b&1) res=1LL*res*a%P;
	return res;
}
int C(int n,int m) {return 1LL*Fac[n]*Pow(Fac[m],P-2)%P*Pow(Fac[n-m],P-2)%P;}
void DFS(int x)
{
	if (x>9*n) return;
	for (int i=0;i<=n&&i*a<=x;i++) if (i*a+(n-i)*b==x) (Ans+=C(n,i))%=P;
	DFS(x*10+a),DFS(x*10+b);
}

int main()
{
	scanf("%d%d%d",&a,&b,&n);
	Fac[0]=1;For(i,1,n+1) Fac[i]=1LL*Fac[i-1]*i%P;
	DFS(a);DFS(b);
	printf("%d\n",Ans);
}