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
in t,n,a1,a2,a3,b1,b2,b3;
void add(in x,in y,in z)
{
	edge[++cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].next=head[x];
	head[x]=cnt;
}

int main()
{
	n=read();
	a1=read();
	a2=read();
	a3=read();
	b1=read();
	b2=read();
	b3=read();
	cout<<n-min(a1,n-b2)-min(a2,n-b3)-min(a3,n-b1)<<" "<<min(a1,b2)+min(a2,b3)+min(a3,b1);
	return 0;
}