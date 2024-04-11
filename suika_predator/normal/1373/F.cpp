#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int a[1111111],b[1111111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		int l=0,r=b[n],fl=0;
		while(l<=r)
		{
			int mid=(l+r)/2,cur=mid,ok=1;
//			cerr<<"chk "<<mid<<endl;
			for(int i=1;i<=n;i++)
			{
//				cerr<<i<<' '<<cur<<endl;
				int tmp=max(0,a[i]-cur);
				if(tmp>b[i])
				{
					l=mid+1;
					ok=0;
					break;
				}
				cur=b[i]-tmp;
			}
			if(!ok)continue;
			if(cur>=mid)
			{
				cout<<"YES"<<endl;
				fl=1;
				break;
			}
			r=mid-1;
		}
		if(!fl)cout<<"NO"<<endl;
	}
	return 0;
}