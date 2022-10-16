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
    int a[N];
    int b[N];
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
    		cin>>n>>k;
    		int sum=0;
    		bool flag=1,jyz=0;
    		for (int i=1;i<=n;i++)
    		{
    			cin>>m;
    			sum+=m;
    			if (m!=k) flag=0;
    			else jyz=1;
    		}
    	if (flag) cout<<0<<endl;
    	else if (jyz||sum==n*k) cout<<1<<endl;
    	else cout<<2<<endl;
    }
    }