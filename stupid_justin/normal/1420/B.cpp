    #include<bits/stdc++.h>
    #define int long long 
    using namespace std;
    const int MAXN = 3e6 + 10, B = 32;
    int n,ch[MAXN][2],a[MAXN],tot;
    int num[MAXN];
    void init() 
    {
        memset(ch,0,sizeof(ch));
        memset(num,0,sizeof(num));
        tot=0;
    }
    void insert(int x) 
    {
        int now=0;
        for(int i=B;i>=0;i--) 
    	{
            bool nxt=(x>>i&1);
            
            if(!ch[now][nxt]) ch[now][nxt]=++tot;
            now=ch[now][nxt];
    		num[now]++;
        }
    }
    int query(int x) 
    {
        int now=0,ret=0;
        for(int i=B;i>=0;i--) 
    	{
            bool nxt=(x>>i&1);
            now=ch[now][nxt];
    //        printf("i:%d nxt:%d now:%d num[now]=%d\n",i,nxt,now,num[now]);
    //        printf("%d:%d\n",i,nxt);
            if (nxt==1/*xi*/) 
    		{
    			ret+=num[now];
    			return ret;
    		}
        }
        return ret;
    }
    signed main() 
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		init();
    		cin>>n;
    		int ans=0;
    		for (int i=1;i<=n;i++) cin>>a[i];
    		for (int i=1;i<=n;i++) 
    		{
    			insert(a[i]);
    			ans+=query(a[i])-1;
    //			cout<<ans<<endl;
    			
    		}
    		cout<<ans<<endl;
    	}
    }