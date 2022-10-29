#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int a[105];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		rep(i,1,n) cin>>a[i];
		int ans=0;
		rep(i,1,k) if(a[i]>k) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}