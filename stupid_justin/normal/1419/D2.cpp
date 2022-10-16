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
    bool vis[N];
    string str;
    map<int,int> Map;
    vector<int> vec[N];
     
    void add(int u,int v){vec[u].push_back(v);vec[v].push_back(u);}
     
     
     
     
    signed main()
    {
    	cin>>n;
    	for (int i=1;i<=n;i++)
    		cin>>a[i];
    	sort(a+1,a+n+1);
    	a[n+1]=inf;
    	int mid=(n-1)/2;
    	if (n==1) printf("0\n%lld\n",a[1]);
    	else if (n==2) printf("0\n%lld %lld\n",a[1],a[2]);
    	else
    	{
    		int tl=mid+1;
    		while (a[tl]<=a[1]) tl++;
    		if (tl==n+1 || tl==n)
    		{
    			cout<<0<<endl;
    			for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    			return 0;
    		}
    		for (int i=1;i<=mid;i++)
    		{
    			
    			b[++cnt]=a[tl];vis[tl]=1;
    			b[++cnt]=a[i];vis[i]=1;
    			tl++;
    			int tmp=tl;
    			while (a[tl]<=a[i+1]) tl++;
    			if (tl==n+1 || tl==n) 
    			{
    				b[++cnt]=a[tmp];vis[tmp]=1;
    				break;
    			}
    		}
    		for (int i=1;i<=n;i++) if (!vis[i]) b[++cnt]=a[i];cnt=0;
    		for (int i=1;i<=n;i++) if (b[i]<b[i-1] && b[i]<b[i+1]) cnt++;
    		cout<<cnt<<endl;
    		for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    	}
    	
     
    }