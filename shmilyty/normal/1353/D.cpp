#include<bits/stdc++.h>
using namespace std;
struct seg{
	int l,r;
	bool operator<(const seg &x)const
	{
		int lena=r-l+1,lenb=x.r-x.l+1;
		if(lena==lenb)
			return l>x.l;
		return lena<lenb;
	}
};
int t,n,ans[200001];
priority_queue<seg> q;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		q.empty();
		scanf("%d",&n);
		q.push((seg){1,n});
		for(int i=1;i<=n;i++)
		{
			seg t=q.top();
			q.pop();
			ans[(t.l+t.r)/2]=i;
			if(t.l<=(t.l+t.r)/2-1)
				q.push((seg){t.l,(t.l+t.r)/2-1});
			if((t.l+t.r)/2+1<=t.r)
				q.push((seg){(t.l+t.r)/2+1,t.r});
		}
		for(int i=1;i<=n;i++)	
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}