    #include<bits/stdc++.h>
    #define int long long
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
    using namespace std;
     
    const int N=2e5+5;
    const int inf=0x3f3f3f3f3f3f3f;
    const int mod1=1e9+7;
    const int mod2=998244353;
     
     
    int n,m,k,ans,cnt,res;
     
    int a[N];
    int dp[N][2];
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n;
    		for (int i=1;i<=n;i++) a[i]=0;
    		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=inf;
    		for (int i=1;i<=n;i++) cin>>a[i];
    		//dp[i][j]ibossj
    		dp[1][0]=inf;
    		dp[1][1]=a[1];
    		dp[2][0]=a[1];
    		dp[2][1]=a[1]+a[2];
    		for (int i=3;i<=n;i++)
    		{
    			dp[i][0]=min(dp[i][0],dp[i-1][1]);
    			dp[i][0]=min(dp[i][0],dp[i-2][1]);
    			dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
    			dp[i][1]=min(dp[i][1],dp[i-2][0]+a[i]+a[i-1]);
    		} 
    		cout<<min(dp[n][0],dp[n][1])<<endl;
    		for (int i=1;i<=n;i++) a[i]=0;
    		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=inf;
    	}
    }