#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005;
bool vis[N],met[N];
int a[N],mx[N];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i],vis[i]=0,mx[i]=0;
		rep(i,1,n) met[i]=0,mx[a[i]]=max(mx[a[i]],i);
		vis[n+1]=vis[n]=1;
		repd(i,n-1,1) vis[i]=(vis[i+1] && a[i]<=a[i+1]);
		int tmp=0,mod=0,ans=n;
		rep(i,0,n)
		{
			if(i)
			{
				tmp=max(tmp,mx[a[i]]);
				if(!met[a[i]]) met[a[i]]=1,++mod;
			}
			if(tmp==i && vis[i+1]) ans=min(ans,mod);
		}
		cout<<ans<<endl;	
	}
	return 0;
}