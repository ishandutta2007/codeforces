#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL C[2010][2010];
int x[MAXN],y[MAXN];
LL b[MAXN];
LL sum1[MAXN],sum2[MAXN];
int n,m,r;
int buc[1010][1010];
int dis(int a,int b)
{
	return max(abs(x[a]-x[b]),abs(y[a]-y[b]));
}

int query(int x1,int x2,int y1,int y2)
{
	if (x1>x2 || y1>y2)
		return 0;
	x1=max(x1,1);
	x2=min(x2,1000);
	y1=max(y1,1);
	y2=min(y2,1000);
	return buc[x2][y2]-buc[x1-1][y2]-buc[x2][y1-1]+buc[x1-1][y1-1];
}

void work()
{
	for (int i=0;i<=2000;i++)
		for (int j=0;j<=i;j++)
		{
			if (i==j || j==0)
				C[i][j]=1;
			else
			{
				C[i][j]=C[i-1][j-1]+C[i-1][j];
				if (C[i][j]>=MOD)
					C[i][j]-=MOD;
			}
		}
	cin>>n>>m>>r;
	LL sumb=0;
	for (int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>b[i];
		buc[x[i]][y[i]]++;
		sumb+=b[i];
	}
	LL ans=sumb*sumb%MOD*C[n][m]%MOD;
	WRT(ans);
	for (int i=1;i<1010;i++)
		for (int j=1;j<1010;j++)
			buc[i][j]+=buc[i-1][j]+buc[i][j-1]-buc[i-1][j-1];
			
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (dis(i,j)>r)
				sum1[i]++;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
		{
			//cout<<i<<' '<<j<<' '<<2*C[sum1[i]][m]*b[i]*b[j]<<' '<<2*C[sum1[j]][m]*b[i]*b[j]<<endl;
			ans-=2*C[sum1[i]][m]*b[i]%MOD*b[j]%MOD+2*C[sum1[j]][m]*b[i]%MOD*b[j]%MOD;
			int tmp=query(max(x[i],x[j])-r,min(x[i],x[j])+r,
						  max(y[i],y[j])-r,min(y[i],y[j])+r);
			tmp=n-(n-sum1[i])-(n-sum1[j])+tmp;
			WRT(C[sum1[i]][m])
			WRT(C[sum1[j]][m])
			WRT(tmp)
			ans+=2*C[tmp][m]*b[i]%MOD*b[j]%MOD;
			//WRT(ans);
		}
	WRT(ans)
	for (int i=0;i<n;i++)
	{
		ans-=C[sum1[i]][m]*b[i]%MOD*b[i]%MOD;
		WRT(C[sum1[i]][m]*b[i]*b[i])
	}
	cout<<(ans%MOD+MOD)%MOD<<endl;
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int casenum=1;
	//scanf("%d",&casenum);
	for (int testcase=1;testcase<=casenum;testcase++)
	{
		#ifdef _DEBUG_
		printf("Case #%d:",testcase);
		#endif
		work();
	}
	return ~~(0^_^0);
}