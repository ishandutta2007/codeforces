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
    int z,f,l;
    int num[N];
    string str;
     
     
     
    signed main()
    {
    	int T;
    	cin>>T;
    	while (T--)
    	{
    		cin>>n;
    		cin>>str;
    		//n
    		int hd=0;
    		for (hd=0;hd<n;hd++) if (str[hd]=='>') break;
    		if (hd==n) {cout<<n<<endl;continue;}
    		for (hd=n-1;hd>=0;hd--)	if (str[hd]=='<') break;
    		if (hd==-1) {cout<<n<<endl;continue;}
    		ans=0;
    		if (str[0]=='-' || str[n-1]=='-') ans++;
    		for (int i=1;i<n;i++) if (str[i]=='-' || str[i-1]=='-') ans++;
    		cout<<ans<<endl;
    	}
    }