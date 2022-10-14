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
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int x[4],y[4],xx[4],yy[4];
int p[4];
LL dis(int x1,int y1,int x2,int y2)
{
	return (LL)abs(x1-x2)+abs(y1-y2);
}

void work()
{
	
	for (int i=0;i<4;i++)
	{
		p[i]=i;
		scanf("%d%d",&xx[i],&yy[i]); 
	}
	LL ans=LLINF;
	vector<int> v;
	for (int i=0;i<24;i++)
	{
		for (int i=0;i<4;i++)
		{
			x[i]=xx[p[i]];
			y[i]=yy[p[i]];
		}
		for (int ii=0;ii<4;ii++)
			for (int jj=0;jj<4;jj++)
			{
				int X=x[ii],Y=y[jj];
				
				v.clear();
				v.push_back(x[1]-X);
				v.push_back(y[2]-Y);
				v.push_back(x[3]-X);
				v.push_back(y[3]-Y);
				sort(v.begin(),v.end());
				int d=v[2];
				//WRT(d);
				//cout<<x[0]+d<<' '<<y[0]<<' '<<x[1]<<' '<<y[1]<<endl; 
				//cout<<x[0]<<' '<<y[0]+d<<' '<<x[2]<<' '<<y[2]<<endl; 
				//cout<<x[0]+d<<' '<<y[0]+d<<' '<<x[3]<<' '<<y[3]<<endl; 
				ans=min(ans,
				dis(X,Y,x[0],y[0])+
				dis(X+d,Y,x[1],y[1])+
				dis(X,Y+d,x[2],y[2])+
				dis(X+d,Y+d,x[3],y[3]));
				} 
		next_permutation(p,p+4);
	}
	printf("%lld\n",ans);
}
 
int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}