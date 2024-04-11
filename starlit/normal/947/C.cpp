#include<bits/stdc++.h>
#define V 9000006
#define N 300005
using namespace std;
int n,a[N],b,rt,sum[V],c[V][2],cnt;
void ins(int &k,int loc)
{
	if(!k)k=++cnt;
	sum[k]++;
	if(loc<0)return;
	if(b>>loc&1)ins(c[k][1],loc-1);
	else ins(c[k][0],loc-1);
}
int qry(int k,int loc,int v)
{
	sum[k]--;
	if(loc<0)return 0;
	int t=v>>loc&1;
	if(sum[c[k][t]])return qry(c[k][t],loc-1,v);
	return qry(c[k][t^1],loc-1,v)|(1<<loc);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",a+i);
	for(int i=0;i<n;i++)
	scanf("%d",&b),ins(rt,29);
	for(int i=0;i<n;i++)
	printf("%d ",qry(rt,29,a[i]));
}