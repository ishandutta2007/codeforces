#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 125

using namespace std;

int a[maxn][5],n,ans,t,b[5],x[5],y[5],p1,p2,tmp;

int check(int s,int r)
{
	if (s*2>r) return 2;
	else if (s*4>r) return 4;
	else if (s*8>r) return 6;
	else if (s*16>r) return 8;
	else if (s*32>r) return 10;
	else return 12;
}

int main()
{
	scanf("%d",&n);
	memset(b,0,sizeof(b));
	for (int i=1;i<=n;i++)
        for (int j=0;j<5;j++)
        {
        	scanf("%d",&a[i][j]);
        	if (a[i][j]>=0) b[j]++;
        }
    for (int i=0;i<5;i++)
    {
    	if (a[1][i]>=0) x[i]=250-a[1][i]; else x[i]=0;
    	if (a[2][i]>=0) y[i]=250-a[2][i]; else y[i]=0;
    }
    t=0;
    while (t<n*32)
    {
    	p1=p2=0;
    	for (int i=0;i<5;i++)
    	{
    	    if (x[i]!=0&&x[i]<y[i]) tmp=check(b[i]+t,n+t); else tmp=check(b[i],n+t);
    	    p1+=x[i]*tmp;p2+=y[i]*tmp;
    	}
    	if (p1>p2){
    		printf("%d\n",t);
    		return 0;
    	}
    	t++;
    }
    printf("-1\n");
    return 0;
}