#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int mod=1000000007;
double ksm(double i,int j)
{
	double x=i,y=1;
	while(j)
	{
		if(j&1)
			y=y*x;
		x=x*x;
		j=j>>1;
	}
	return y;
}
double k[100010];
int main()
{
    int n,m,n1;
    double ans=0;
    cin>>n>>m;
    for(n1=1;n1<=n;n1++)
    	k[n1]=ksm(n1/(double)n,m);
    for(n1=1;n1<=n;n1++)
    	ans+=n1*(k[n1]-k[n1-1]);
    printf("%.20f",ans);
}