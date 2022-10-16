    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod=1e9+7;
    int n,len,cnt,ans;
    int pera,perab;
    int per[3][4];
    string str;
    int ksm(int x,int y,int z)
    {
    	int ret=1;
    	while (y)
    	{
    		if (y&1) ret=(ret*x)%z;
    		x=(x*x)%z;
    		y>>=1;
    	}
    	return ret;
    }
    signed main()
    {
    	cin>>n;
    	cin>>str;
    	len=str.length();
    	for (int i=0;i<len;i++)
    	{
    		if (str[i]=='?') cnt++;
    	}
    	for (int i=0;i<len;i++)
    	{
    		if (str[i]=='a') per[0][0]++;
    		if (str[i]=='b') for (int j=0;j<=1;j++) per[1][j]+=per[0][j],per[1][j]%=mod;
    		if (str[i]=='c') for (int j=0;j<=2;j++) per[2][j]+=per[1][j],per[2][j]%=mod;
    		if (str[i]=='?')
    		{
    			for (int j=0;j<=2;j++) per[2][j+1]+=per[1][j],per[2][j+1]%=mod;
    			for (int j=0;j<=1;j++) per[1][j+1]+=per[0][j],per[1][j+1]%=mod;
    			per[0][1]++;
    		}
    	}
    	for (int i=0;i<=3;i++) if (cnt>=i) ans+=ksm(3,cnt-i,mod)*per[2][i],ans%=mod;
    	cout<<ans<<endl;
    }