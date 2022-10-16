#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int t[N],h[N],l[N],r[N],cnt[N];
int n,ans,pos;
signed main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&t[i]);
	for(int i=1;i<n;i++) if(t[i]>t[pos]) pos=i;
	for(int i=0;i<=n;i++) h[i]=t[(i+pos)%n];
	for(int i=1;i<=n;i++)
    {
		l[i]=i-1;
		while(l[i] && h[i]>=h[l[i]]) l[i]=l[l[i]];
	}
	for(int i=n-1;i>=0;i--)
    {
		r[i]=i+1;
		while(r[i]<n && h[i]>h[r[i]]) r[i]=r[r[i]];
		if(r[i]<n && h[i]==h[r[i]])
        {
			cnt[i]=cnt[r[i]]+1;
			r[i]=r[r[i]];
		}
	}
	for(int i=0;i<n;i++)
    {
		ans+=cnt[i];
		if(h[i]<h[0])
        {
			ans+=2;
			if(!l[i] && r[i]==n)
				ans--;
		}
	}
	cout<<ans<<endl;
}