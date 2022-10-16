    #include<bits/stdc++.h>
    #define int long long
    #define rd(x) x=read()
    using namespace std;
    const int N=2e5+5;
    const int M=5005;
    const int mod=998244353;
    inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
    int T;
    string s;
    int l,L,ans;
    int n,q,x;
    bool flag;
    int a[N];
    int mxpre[N],mnpre[N],mxsuf[N],mnsuf[N],now[N];
    void debug(int x){cerr<<x<<endl;}
    void print(int *f,int n)
    {
    	for (int i=0;i<=n;i++) cout<<f[i]<<" ";cout<<endl;
    }
    signed main()
    {
    	cin>>T;
    	while (T--)
    	{
    		rd(n);rd(q);
    		cin>>s;s=" "+s;
    		for (int i=0;i<=n+5;i++) mxpre[i]=mnpre[i]=mxsuf[i]=mnsuf[i]=0;
    		x=0;
    		for (int i=1;i<=n;i++)
    		{
    			if (s[i]=='-') x--;else x++;
    			mxpre[i]=max(mxpre[i-1],x);
    			mnpre[i]=min(mnpre[i-1],x);
    			now[i]=x;
    		}
    		for (int i=n;i>=1;i--)
    		{
    			if (s[i]=='-')
    			{
    				mxsuf[i]=max(0LL,mxsuf[i+1]-1);
    				mnsuf[i]=min(0LL,mnsuf[i+1]-1);
    			}
    			if (s[i]=='+')
    			{
    				mxsuf[i]=max(0LL,mxsuf[i+1]+1);
    				mnsuf[i]=min(0LL,mnsuf[i+1]+1);
    			}
    		}
    		while (q--)
    		{
    			int l,r;
    			rd(l);rd(r);
    			int L=mnpre[l-1],R=mxpre[l-1];
    			L=min(now[l-1]+mnsuf[r+1],L);
    			R=max(now[l-1]+mxsuf[r+1],R);
    			cout<<R-L+1<<"\n";
    		}
    	}
    }