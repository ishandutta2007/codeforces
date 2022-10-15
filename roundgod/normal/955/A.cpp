#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll hh,mm,H,D,C,N;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&hh,&mm,&H,&D,&C,&N);
	ll tt=0;
	if(hh<20) tt=(20-hh)*60-mm; else tt=0;
	printf("%.10f\n",(double)min(((H-1)/N+1)*C*5,((H+tt*D-1)/N+1)*4*C)/5.0);
	return 0;
}