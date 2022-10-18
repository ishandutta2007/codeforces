#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long N = 1000000007ll;
vector<long long> p;
void Solve(long long n)  
{  
    p.clear();  
    for(long long i=2; i*i<=n; i++)  
    {  
        if(n%i==0)  
        {  
            p.push_back(i);
			n/=i;  
            while(n%i==0) 
			{
				p.push_back(i);
				n/=i;
			}  
        }  
    }  
    if(n>1)  p.push_back(n); 
}

struct Matrix
{
    int  m[55][55];
} I,A,T;
Matrix matrixmul(Matrix a,Matrix b)
{
    int i,j,k;
    Matrix c;
    for (i=0; i<=52; i++)
        for(j=0; j<=52; j++)
        {
            c.m[i][j]=0;
            for(k=0; k<=52; k++)
            {
                c.m[i][j]+=(a.m[i][k]*b.m[k][j]);
                c.m[i][j]%=N;
            }
        }
    return c;
}
Matrix quickpagow(int n)
{
    Matrix m=A,b=I;
    while (n>=1)
    {
        if(n&1)
            b=matrixmul(b,m);
        n=n>>1;
        m=matrixmul(m,m);
    }
    return b;
}
long long pw(long long n,int x)
{
	if(x==0) return 1;
	if(x&1) return(pw(n,x-1)*n)%N;
	long long s = pw(n,x/2);
	return(s*s)%N;
}
main()
{
	long long n,k;
	scanf("%lld %lld",&n,&k);
    for(int i=0; i<=52; i++)
    {
            I.m[i][i]=1;
    }
    for(int i = 0;i<=52;i++) for(int j = 0;j<=i;j++) A.m[i][j] = pw(53-j,N-2);
    T=quickpagow(k);
	Solve(n);
	int pos = 0;
	int t = 0;
	long long ans = 1;
	p.push_back(0);
	for(int i = 0;i<p.size();i++)
	{
		if(!pos) 
		{
			pos = p[0];
			t = 1;
			continue;
		}
		if(pos!=p[i])
		{
			long long sum = 0;		
			for(int j = t;j>=0;j--)
			{
				sum = (sum+(long long)T.m[52-j][52-t]*pw(pos,j))%N;
			}
			ans = (ans*sum)%N;
			pos = p[i];
			t = 1;
		}
		else t++;
	}
	printf("%lld\n",(ans+N)%N);
}