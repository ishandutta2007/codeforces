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
     
     
    int n,ans;
    string s;
    char str[N];
     
    struct TwoList
    {
        int pre,nxt;
    }L[N];
    void Delete(int x)
    {
        if (L[x].pre) L[L[x].pre].nxt=L[x].nxt;
        if (L[x].nxt) L[L[x].nxt].pre=L[x].pre;
    }
     
     
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>s;
    		n=s.length();
    		ans=n;
    		for (int i=1;i<=n;i++) str[i]=s[i-1];
    		for (int i=1;i<=n;i++)
    		{
    			L[i].nxt=i+1;
    			L[i].pre=i-1;
    		}
    		L[1].pre=0;
    		L[n].nxt=-1;
    		for (int i=1;i<=n;i++)
    		{
    			if (L[i].pre)
    			{
    				if (str[i]=='B' & str[L[i].pre]=='B') 
    				{
    					Delete(L[i].pre);
    					Delete(i);
    					ans-=2;
    				}
    				else
    				if (str[i]=='B' & str[L[i].pre]=='A') 
    				{
    					Delete(L[i].pre);
    					Delete(i);
    					ans-=2;
    				}
    			}
    		}
    		printf("%lld\n",ans);
    	}
    }