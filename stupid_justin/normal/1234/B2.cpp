#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+5;
const int inf=0x3f3f3f3f;
int que[N];
int head,tail;
int n,k;
int id[N];
int idn[N];
bool vis[N];
int num[N];
void hashs()
{
	int ttt=1;
	sort(idn+1,idn+n+1);
	num[ttt]=idn[1];
	for (int i=2;i<=n;i++)
	{
		if (idn[i]!=idn[i-1])
		{
			ttt++;
			num[ttt]=idn[i];
		}
	}
}
int main()
{
	cin>>n>>k;
	head=2e5+1;
	tail=2e5;
	memset(num,inf,sizeof(num));
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++) cin>>id[i];
	for (int i=1;i<=n;i++) idn[i]=id[i];
	hashs();
	for (int i=1;i<=n;i++)
	{
		//change id[i];
		int lt=1;int rt=n;
		int mid=(lt+rt)>>1;
		while(1)
		{
			mid=(lt+rt)>>1;
//			cout<<mid<<endl;
			if (num[mid]==id[i])
			{
				id[i]=mid;break;
			}
			if (num[mid-1]==id[i])
			{
				id[i]=mid-1;break;
			}
			if (num[mid+1]==id[i])
			{
				id[i]=mid+1;break;
			}
			if (num[mid]<id[i])
			{
				lt=mid;
			}
			if (num[mid]>id[i])
			{
				rt=mid;
			}
		}
//		cout<<id[i]<<endl;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[id[i]])
		{
			head--;
			que[head]=id[i];
			vis[id[i]]=1;
			if (tail-head+1>k) 
			{
				vis[que[tail]]=0;
				tail--;
			}
		}
	}
	cout<<tail-head+1<<endl;
	for (int i=head;i<=tail;i++) cout<<num[que[i]]<<" ";
}