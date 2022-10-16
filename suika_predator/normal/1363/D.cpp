#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,tmp;
string s;
int siz[1111],a[1111][1111],bel[1111],fl[1111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(bel,0,sizeof(bel));
		for(int i=1;i<=k;i++)
		{
			cin>>siz[i];
			for(int j=1;j<=siz[i];j++)
			{
				cin>>a[i][j];
				bel[a[i][j]]=i;
			}
		}
		cout<<"? "<<n;
		for(int i=1;i<=n;i++)cout<<' '<<i;
		cout<<endl;
		cin>>m;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)/2;
			cout<<"? "<<mid-l+1;
			for(int i=l;i<=mid;i++)cout<<' '<<i;
			cout<<endl;
			cin>>tmp;
			if(tmp==m)r=mid;
			else l=mid+1;
		}
		int sp=bel[l];
		if(sp!=0)
		{
			memset(fl,0,sizeof(fl));
			for(int i=1;i<=siz[sp];i++)fl[a[sp][i]]=1;
			cout<<"? "<<n-siz[sp];
			for(int i=1;i<=n;i++)if(!fl[i])cout<<' '<<i;
			cout<<endl;
			cin>>tmp;
		}
		cout<<"!";
		for(int i=1;i<=k;i++)
		{
			if(i==sp)cout<<' '<<tmp;
			else cout<<' '<<m;
		}
		cout<<endl;
		cin>>s;
		if(s=="Incorrect")break;
	}
	return 0;
}