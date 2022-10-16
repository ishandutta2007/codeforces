    #include<bits/stdc++.h>
    #define int long long
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
     
    using namespace std;
     
    const int N=1e5+5;
    const int inf=0x3f3f3f3f3f3f3f3f;
    const int mod=1e9+7;
    const int mod2=998244353;
    int n,m;
    int a[N];
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n>>m;
    		for (int i=1;i<=n;i++) cin>>a[i];
    		int sum=0;
    		for (int i=1;i<=n;i++) sum+=a[i];
    		if (sum==m) cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    	}
    }