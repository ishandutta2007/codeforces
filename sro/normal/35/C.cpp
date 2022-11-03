#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int INF=1000000000 ;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k,fx[15],fy[15],i,j,l,maxn=-INF,nn,minnn,mx,my;
	scanf("%d %d\n%d",&n,&m,&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %d",&fx[i],&fy[i]);fx[i]--;fy[i]--;
	}
	//
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			minnn=INF;
			for(l=0;l<k;l++)
			{
				nn=abs(i-fx[l])+abs(j-fy[l]);
				minnn=min(minnn,nn);
			}
			if(maxn<minnn)
				maxn=minnn,mx=i,my=j;
		}
	return printf("%d %d\n",mx+1,my+1),0;
}