    #include<bits/stdc++.h>
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
    #define int long long
    using namespace std;
     
    const int N=3e5+5;
    const int inf=0x3f3f3f3f;
    const int mod=1e9+7;
    const int mod2=998244353;
     
    int n,x,pos;
    int ans;
    int xiao,da;
    signed main()
    {
    	cin>>n>>x>>pos;
    	int l=0,r=n;
    	ans=1;
    	while (l<r)
    	{
    		int mid=(l+r)/2;
    		if (mid<=pos)
    		{
    			if (mid!=pos) xiao++;
    			l=mid+1;
    		}
    		else
    		{
    			da++;
    			r=mid;
    		}
    	}
    	for (int i=1;i<=xiao;i++) ans=(ans*(x-i))%mod;
    	for (int i=1;i<=da;i++) ans=(ans*(n-x-i+1))%mod;
    	for (int i=1;i<=n-xiao-da-1;i++) ans=(ans*i)%mod;
    	cout<<ans<<endl;
    }