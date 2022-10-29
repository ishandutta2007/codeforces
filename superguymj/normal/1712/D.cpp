#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
const int N=100005,INF=1000000000;
int n,k,p[N],a[N],b[N],ans;

bool cmp(int x,int y) {return a[x]<a[y];}

int get(int mx=0)
{
	rep(i,1,n-1) mx=max(mx,min(a[i],a[i+1]));
	int mn=INF;
	rep(i,1,n) mn=min(mn,a[i]);
	return min(2*mn,mx);
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n) b[i]=a[i];

		int mx=0;
		rep(i,1,n) mx=max(mx,a[i]);
		ans=get(mx);

		rep(i,1,n) p[i]=i;
		sort(p+1,p+1+n,cmp);
		rep(i,1,k-1) a[p[i]]=INF;
		ans=max(ans,get(k>1?INF:0));
		a[p[k]]=INF;
		ans=max(ans,get());
		cout<<ans<<endl; 	
	}
	return 0;
}