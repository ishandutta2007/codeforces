

    #include<bits/stdc++.h>
    #define int long long
    #define rd(x) x=read()
    using namespace std;
     
    const int N=3e5+5;
    const int mod=998244353;
    inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
    int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
     
    int n,m,la; 
    int k[N],c[N];
    string s;
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		rd(n);la=0;
    		cin>>s;
    		for (int i=0;i<n;i++)
    		{
    			if (s[i]=='0' && la==0) putchar('1'),la=1;else
    			if (s[i]=='0' && la==1) putchar('0'),la=0;else
    			if (s[i]=='0' && la==2) putchar('1'),la=1;else
    			if (s[i]=='1' && la==0) putchar('1'),la=2;else
    			if (s[i]=='1' && la==1) putchar('1'),la=2;else
    			if (s[i]=='1' && la==2) putchar('0'),la=1;
    		}
    		putchar('\n');
    	}
    }