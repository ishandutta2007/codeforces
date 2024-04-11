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
    		int x1,x2,y1,y2;
    		cin>>x1>>y1>>x2>>y2;
    		if (x1==x2)
    		{
    			cout<<abs(y1-y2)<<endl;
    		}
    		else
    		if (y1==y2)
    		{
    			cout<<abs(x1-x2)<<endl;
    		}
    		else
    		{
    			cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
    		}
    	}
    }