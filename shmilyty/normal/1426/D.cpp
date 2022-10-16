#include<bits/stdc++.h>
using namespace std;
#define in long long
const in inf=114514114514114514;
const int INF=1e9;
const in mod=0; 
struct node{
	int to,val,next;
} edge[199999];
inline in read()
{
    in X=0; 
	bool flag=1; 
	char ch=getchar();
    while(ch<'0'||ch>'9') 
	{
		if(ch=='-') 
			flag=0; 
		ch=getchar();
	}
    while(ch>='0'&&ch<='9') 
	{
		X=(X<<1)+(X<<3)+ch-'0'; 
		ch=getchar();
	}
    if(flag) 
		return X;
    return ~(X-1);
}
in cnt,head[100001];
in t,n,x,sum,ans;
map<in,in> ma;
void add(in x,in y,in z)
{
	edge[++cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].next=head[x];
	head[x]=cnt;
}

int main()
{
	ma[0]=1;
	n=read();
	for(in i=1;i<=n;i++)
	{
		x=read();
		sum+=x;
		if(ma[sum])
		{
			ans++;
			sum=x;
			ma.clear();
			ma[0]=1;
		}
		ma[sum]=1;
	}
	cout<<ans;
	return 0;
}