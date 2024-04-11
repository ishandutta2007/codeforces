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
     
    int n,m,sum,Max1,Max2;
    string s1,s2,s3,s4;
    int a[N];
    int dp[N][2];
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>s1>>s2;
    		s3="-1";
    		n=s1.length(),m=s2.length();
    		for (int i=1;i<=__gcd(n,m);i++)
    		{
    			if (n%i!=0) continue;
    			if (m%i!=0) continue;
    			bool  flag=1;
    			for (int j=0;j<n;j++) if (s1[j]!=s1[j%i]) flag=0; 
    			for (int j=0;j<m;j++) if (s2[j]!=s1[j%i]) flag=0;
    			if (flag) 
    			{
    				s4="";
    				for (int j=0;j<i;j++) s4=s4+s1[j];
    				s3=s4;
    			 } 
    		}
    		if (s3=="-1") cout<<s3;else
    		for (int i=1;i<=n*m/__gcd(n,m)/__gcd(n,m);i++) cout<<s3;
    		puts("");
    	}
    }