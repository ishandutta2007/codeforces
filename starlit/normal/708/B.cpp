#include<bits/stdc++.h>
#define exi return puts("Impossible"),0
using namespace std;
int n,a00,a01,a10,a11,x,y,z,now;
bool qwq;
int main()
{
	scanf("%d%d%d%d",&a00,&a01,&a10,&a11);
	if(a00==0&&a11==0&&a01==0&&a10==0)
    return puts("0"),0;
	a00<<=1,a11<<=1;
	if(a00||a10||a01)
	for(x=1;x*(x-1)<a00;x++);
	if(x*(x-1)>a00)exi;
	if(a01||a10||a11)
	for(y=1;y*(y-1)<a11;y++);
	if(y*(y-1)>a11)exi;
	if(x*y!=a01+a10)exi;
	while(x)
    {
        if(now+y>a10)break;
        z++,x--,now+=y;
    }
    if(a10-now)qwq=1;
    for(int i=0;i<x-qwq;i++)
    printf("0");
    for(int i=0;i<a10-now;i++)
    printf("1");
    if(qwq)printf("0");
    for(int i=a10-now;i<y;i++)
    printf("1");
    for(int i=0;i<z;i++)
    printf("0");
}