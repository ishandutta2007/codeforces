#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef double D;

int N;
D P[19][19], memo[1<<19];

int bc(int n)
{
	int r=0;
	while(n) n&=(n-1),r++;
	return r;
}

D get(int cm)
{
	if(cm==(1<<N)-1) return 1.0;
	if(memo[cm]>-0.5) return memo[cm];
	D r = 0.0; 
	int count=0;
	
	for(int i=0;i<N;i++) for(int j=0;j<N;j++)
	{
		if( (cm&(1<<i))!=0 && (cm&(1<<j))==0 )
		{
			r+=P[i][j]*get(cm|(1<<j));
			//count++;
		}
	}
	count=bc(cm);
	//if(count>0) r/=(0.5*count);
	r/=(0.5*count*(count+1));

	return memo[cm] = r;
}

int main()
{
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf("%lf",&P[i][j]);

	for(i=0;i<(1<<N);i++) memo[i] = -1.0;
	memo[(1<<N)-1] = 1.0;
	
	for(i=0;i<N;i++) printf("%lf ",get(1<<i));
	puts("");

	return 0;
}