#include<bits/stdc++.h>
using namespace std;
int a[233333],bel[233333];
int lst[233333],tonx[233333],go[233333];
const int B=300;
int L[2333],R[2333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bel[i]=i/B;
		if(not L[i/B])L[i/B]=i;
		R[i/B]=i;
	}
	for(int i=n+1;i<=n+n;i++)bel[i]=114514;
	auto rebuild=[&](int b)
	{
		for(int i=R[b];i>=L[b];i--)
		{
			if(bel[i+a[i]]!=bel[i])
			{
				tonx[i]=1;
				go[i]=i+a[i];
				lst[i]=i;
			}
			else
			{
				tonx[i]=tonx[i+a[i]]+1;
				go[i]=go[i+a[i]];
				lst[i]=lst[i+a[i]];
			}
		}
	};
	for(int b=bel[n];b>=bel[1];b--)rebuild(b);
//	for(int i=1;i<=n;i++)cerr<<go[i]<<' '<<tonx[i]<<endl;
	while(q--)
	{
		int ty,pos,w;
		cin>>ty;
		if(ty==0)
		{
			cin>>pos>>w;
			a[pos]=w;
			rebuild(bel[pos]);
		}
		else
		{
			cin>>pos;
			int tot=0,ans1=0;
			while(pos<=n)
			{
				ans1=lst[pos];
				tot+=tonx[pos];
				pos=go[pos];
			}
			cout<<ans1<<' '<<tot<<"\n";
		}
	}
	
	return 0;
}