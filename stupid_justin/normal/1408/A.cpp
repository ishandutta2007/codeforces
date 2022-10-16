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
     
    I int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}}
     
    int n,m,k,ans,cnt,res;
    int a[4][N];
    int f[N];
    int num[N];
    string str;
    map<int,int> Map;
    vector<int> vec[N];
     
    void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}
     
     
     
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n;
    		for (int i=1;i<=n;i++) cin>>a[1][i];
    		for (int i=1;i<=n;i++) cin>>a[2][i];
    		for (int i=1;i<=n;i++) cin>>a[3][i];
    		for (int i=1;i<=n-1;i++)
    			for (int j=1;j<=3;j++) 
    				if (a[j][i]!=f[i-1]) 
    					f[i]=a[j][i];
    		for (int j=1;j<=3;j++) if (a[j][n]!=f[n-1] && a[j][n]!=f[1]) f[n]=a[j][n];
    		for (int i=1;i<=n;i++) printf("%lld ",f[i]);printf("\n");
    	}
    }