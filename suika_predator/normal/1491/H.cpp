#include<bits/stdc++.h>
using namespace std;
const int N=111111,B=323;

int a[N],bel[N],f[N];
int lazy[N/B+5];
int L[N/B+5],R[N/B+5];
inline int getfa(int x)
{
	if(x==1)return 0;
	return max(a[x]-lazy[bel[x]],1);
}
void rebuild(int id)
{
	if(id==0)return;
	for(int i=L[id];i<=R[id];i++)
	{
		int px=getfa(i);
		if(bel[i]==bel[px])
			f[i]=f[px];
		else
			f[i]=i;
	}
}
void change(int l,int r,int x)
{
	if(bel[l]==bel[r])
	{
		for(int i=l;i<=r;i++)
			a[i]=max(a[i]-x,1);
		rebuild(bel[l]);
	}
	else
	{
		for(int i=l;i<=R[bel[l]];i++)
			a[i]=max(a[i]-x,1);
		rebuild(bel[l]);
		for(int i=L[bel[r]];i<=r;i++)
			a[i]=max(a[i]-x,1);
		rebuild(bel[r]);
		for(int i=bel[l]+1;i<=bel[r]-1;i++)
		{
			if(lazy[i]>B)lazy[i]=min(lazy[i]+x,1000000);
			else
			{
				lazy[i]=min(lazy[i]+x,1000000);
				rebuild(i);
			}
		}
	}
}
int query(int x,int y)
{
	while(f[x]!=f[y])
	{
//		cerr<<"fly "<<x<<' '<<y<<' '<<f[x]<<' '<<f[y]<<endl;
		int px=getfa(f[x]),py=getfa(f[y]);
		if(px>py)x=px;
		else y=py;
	}
	while(x!=y)
	{
//		cerr<<"go "<<x<<' '<<y<<endl;
		int px=getfa(x),py=getfa(y);
		if(px>py)x=px;
		else y=py;
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	a[1]=1;f[1]=1;
	bel[1]=0;L[0]=R[0]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		bel[i]=(i+B-2)/B;
		if(bel[i]!=bel[i-1])L[bel[i]]=i;
		R[bel[i]]=i;
	}
	for(int i=1;i<=bel[n];i++)rebuild(i);
	int ty,l,r,x;
	while(q--)
	{
		cin>>ty;
		if(ty==1)
		{
			cin>>l>>r>>x;
			change(l,r,x);
		}
		else
		{
			cin>>l>>r;
			cout<<query(l,r)<<endl;
		}
	}
	return 0;
}