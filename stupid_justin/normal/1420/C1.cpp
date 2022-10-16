    #include<bits/stdc++.h>
    #define int long long
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
     
    using namespace std;
     
    const int N=3e5+5;
    const int inf=0x3f3f3f3f;
    const int mod=1e9+7;
    const int mod2=998244353;
     
    I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}}
     
    int n,m,k,ans,cnt,res,q;
    int a[N];
    int b[N];
    int num[N];
    int p[N];
    int sz[N];
    bool vis[N];
    int fa[N];
    int dp[N][2];
    string str;
    map<int,int> Map;
    vector<int> vec[N];
     
    void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}
     
    void dfs(int x)
    {
    	vis[x]=1;
        for(int i=0;i<vec[x].size();i++)
        {
            if(!vis[vec[x][i]])
            {
            	fa[vec[x][i]]=x;
            	dfs(vec[x][i]);
                sz[x]+=sz[vec[x][i]];
            }
        }
        sz[x]++;
    }
     
     
     
    signed main()
    {
    	srand(time(NULL));
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n>>q;
    		for (int i=1;i<=n;i++) cin>>a[i];
    		for (int i=1;i<=n;i++) 
    		{
    			dp[i][0]=max(dp[i-1][1]+a[i],dp[i-1][0]);
    			dp[i][1]=max(dp[i-1][0]-a[i],dp[i-1][1]);
    		}
    		cout<<max(dp[n][0],dp[n][1])<<endl;
    		for (int i=1;i<=n;i++) dp[i][0]=dp[i][1]=0;
    	}
    }