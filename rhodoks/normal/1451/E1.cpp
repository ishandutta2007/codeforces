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

int a[MAXN];
int n;
int b[MAXN];
int main()
{
	/*
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				cout<<i<<j<<k<<(i^j)<<(i^k)<<(i&k)<<(j|k)<<endl;
	set<int> st;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<2;k++)
				for (int p=0;p<2;p++)
				{
					st.insert((i^j)+(i^k)*2+(i^p)*4+(i&j)*8+(k&p)*16);
					cout<<i<<j<<k<<p<<(i^j)<<(i^k)<<(i^p)<<(j&p)<<(k&p)<<endl;
				}
	WRT(st.size())
	*/
	#ifdef _DEBUG_
	//freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		printf("XOR %d %d\n",1,i); 
		fflush(stdout);
		scanf("%d",&b[i]);
		WRT(b[i])
	}
	int x,y,z;
	while (1)
	{
		x=rand()&(n-1);
		y=rand()&(n-1);
		z=rand()&(n-1);
		x++,y++,z++;
		if (x==y || y==z || x==z)
			continue;
		bool f=1;
		for (int i=1;i<n;i*=2)
			if ((b[x]&i)==(b[y]&i) && (b[y]&i)!=(b[z]&i))
			{
				f=0;
				break;
			}
		if (f==1)
			break;
	}
	//cout<<x<<' '<<y<<' '<<z<<endl;
	int vx,vy,vz;
	int t1,t2;
	printf("AND %d %d\n",x,z); 
	fflush(stdout);
	scanf("%d",&t1);
	printf("OR %d %d\n",y,z); 
	fflush(stdout);
	scanf("%d",&t2);
	for (int i=0;i<n;i++)
	{
		vx=(i^b[x]);
		vy=(i^b[y]);
		vz=(i^b[z]);
		//cout<<vx<<' '<<vy<<' '<<vz<<endl;
		//cout<<(vx & vy)<<' '<<(vx | vz)<<endl;
		if ((vx & vz)==t1 && (vy | vz)==t2)
		{
			a[1]=i;
			for (int j=1;j<=n;j++)
				a[j]=a[1]^b[j];
			//MRK();
			break;
		}
	}
	cout<<"! ";
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	fflush(stdout);
	return ~~(0^_^0);
}