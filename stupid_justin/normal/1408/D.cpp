    #include<bits/stdc++.h>
    #define int long long
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
     
    using namespace std;
     
    const int N=2005;
    const int M=1e6+5;
    const int inf=0x3f3f3f3f3f3f3f3f;
    const int mod=1e9+7;
    const int mod2=998244353;
     
    int n,m;
    vector<int>v;
    vector<int>work;
    vector<int>work1;
    vector<int>uu;
    int num[N][N];
    int a[N],b[N],c[N],d[N];
    int L[N*N],U[N*N];
    int cnt;
    struct Node
    {
    	int l;int u;
    }Q[N*N];
    bool cmp(Node x,Node y)
    {
    	return x.u>y.u;
    }
    int maxl,maxr;
    map<int,int> Map;
    signed main()
    {
    	cin>>n>>m;
    	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    	for (int i=1;i<=m;i++) cin>>c[i]>>d[i];
    	for (int i=1;i<=n;i++)
    		for (int j=1;j<=m;j++)
    			L[++cnt]=max(0LL,-a[i]+c[j]+1),U[cnt]=max(0LL,-b[i]+d[j]+1);
     
    	for (int i=1;i<=cnt;i++) Q[i].l=L[i],Q[i].u=U[i];
    	sort(Q+1,Q+cnt+1,cmp);
    //	for (int i=1;i<=cnt;i++) printf("%lld ",Q[i].u);printf("\n"); 
    //	for (int i=1;i<=cnt;i++) printf("%lld ",Q[i].l);printf("\n"); 
    	for (int i=1;i<=cnt;i++) maxl=max(Q[i].l,maxl),maxr=max(Q[i].u,maxr);
    	int ans=inf;
    	int maxx=0;
    	for (int i=1;i<=cnt+1;i++)
    	{
    		if (i!=1 && Q[i-1].u>Q[i].u)
    			ans=min(ans,Q[i].u+maxx);
    		maxx=max(maxx,Q[i].l);
    	}
    	ans=min(ans,maxl);
    	ans=min(ans,maxr);
    	cout<<ans<<endl;
    }