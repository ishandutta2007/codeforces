    #include<bits/stdc++.h>
    #define int long long
    #define rd(x) x=read()
    using namespace std;
    const int N=2e6+5;
    const int M=5005;
    const int mod=998244353;
    const int inf=0x3f3f3f3f3f3f3f;
    inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
    int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
     
    int n,m,k,t;
    int a[N],tl;
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		rd(n);rd(k);
    		m=2*k-n;
    		for (int i=1;i<=m-1;i++) cout<<i<<" ";
    		for (int i=m;i<=k;i++) cout<<k-i+m<<" ";
    		puts("");
    	}
    }