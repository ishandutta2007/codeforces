#include <iostream>
#include <cstring>

using namespace std;

int b,d,ans,f[1000];

int gcd(int a,int b)
{
	if (b==0) return a; else return gcd(b,a%b);
}

int lcm(int a,int b)
{
	return a*b/gcd(a,b);	
}

int main()
{
	cin>>b>>d;
	if (d==b+1) ans=11; else
	{
		memset(f,127,sizeof(f));
		ans=7;
		f[b+1]=11;
		for (int i=2;i<=b;i++)
			if ((b+1)%i==0) f[i]=11;
		for (int i=2;i<=b-1;i++)
			if ((b-1)%i==0) f[i]=3;
		for (int i=1;i<=b;i++)
			if (b%i==0) f[i]=2;
		for (int i=1;i<=d;i++)
			for (int j=1;j<=i;j++)
				if ((i%j==0)&&(f[j]==2)&&(f[i/j]==2)) f[i]=2;
		if (f[d]>=100)
		for (int i=1;i<=d-1;i++)
			if ((i==1)||(f[i]==3))
				for (int j=1;j<=d-1;j++)
					if ((j==1)||(f[j]==11))
						if (((d%lcm(i,j))==0)&&(f[d/lcm(i,j)]==2)) ans=6;
		if ((ans==7)&&(f[d]<100)) ans=f[d];
	}
	cout<<ans<<"-type"<<endl;
	if (ans==2)
	{
		long long k=1;
		for (int i=1;i<=10;i++)		
		{
			k=(long long)k*b;
			if (k%d==0)
			{
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}