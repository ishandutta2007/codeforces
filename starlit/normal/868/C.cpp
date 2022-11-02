#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005
using namespace std;
int n,m,x,tp;
bool qwq[20];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
    {
        tp=0;
        for(int j=0;j<m;j++)
        scanf("%d",&x),tp=tp<<1|x;
        qwq[tp]=1;
    }
    for(int i=0;i<(1<<m);i++)
    if(qwq[i])
    {
        for(int j=0;j<(1<<m);j++)
        if(qwq[j]&&!(i&j))
        {puts("YES");return 0;}
    }
    puts("NO");
}