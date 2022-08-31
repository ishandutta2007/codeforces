#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;
#define INF 2123456789

int N, bestind = -1;
double pos[105];
double vb,vs,xu,yu;
double besttime = INF, bestud = INF;

double dis(double x1,double y1,double x2,double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));	
}

int main()
{
	int i,j,k;
	scanf("%d %lf %lf",&N,&vb,&vs);
	for(i=1;i<=N;i++) scanf("%lf",&pos[i]);
	scanf("%lf %lf",&xu,&yu);
	
	for(i=2;i<=N;i++)
	{
		double time = pos[i]/vb;
		double ud = dis(xu,yu,pos[i],0.0);
		time+=ud/vs;
		
		if(abs(time-besttime)<1e-7)
		{
			bestud=ud; bestind=i;
		}
		else if(time<besttime)
		{
			besttime=time; bestud=ud; bestind=i;
		}
	}	
	
	printf("%d",bestind);
		
	return 0;
}