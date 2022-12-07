#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
double di[110];
double dp[110][110];
const double e=2.718281828459;
double cal(double r,double d){
	if(r>d) return 1.0;
	return pow(e,(1.0-(d*d/r/r)));
}
int main()
{
	int x,y,nx,ny,n,m,p,i,j,k;
//	cout<<cal(3.84257761518762740,5.0)<<endl;
	scanf("%d",&n);scanf("%d %d",&m,&p);scanf("%d %d",&nx,&ny);
	double a=0.0,b=1e10,pr=1.0-0.001*p;
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		di[i]=sqrt(1.0*(nx-x)*(nx-x)+1.0*(ny-y)*(ny-y));
	}
//	cout<<di[0]<<endl;
//	cout<<pr<<endl;
	for(i=0;i<100;i++){
		double z=(a+b)/2,x=0.0;;
		for(j=0;j<110;j++) for(k=0;k<110;k++) dp[j][k]=0.0;dp[0][0]=1.0;
		for(j=0;j<n;j++){
			double f=cal(z,di[j]);
			for(k=0;k<=n;k++){
				dp[j+1][k]+=dp[j][k]*(1.0-f);dp[j+1][k+1]+=dp[j][k]*f;
			}
		}
		for(j=m;j<=n;j++) x+=dp[n][j];
		if(x>pr) b=z;else a=z;
	}
	printf("%.10f\n",(a+b)/2);
	return 0;
}