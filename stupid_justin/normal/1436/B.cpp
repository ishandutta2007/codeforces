    #include<bits/stdc++.h>
    #define pii pair<int,int>
    #define mp make_pair
    #define fi first
    #define se second
    #define R register
    #define I inline
    #define int long long
    using namespace std;
    int T,n,p;
    bool chk(int x)
    {
        if (x==1) return 1;
        for (int i=2;i<=sqrt(x);i++) if (x%i==0) return 0;
        return 1;
    }
    signed main()
    {
        cin>>T;
        while(T--)
        {
            cin>>n;
            p=1;
            while(!chk(4*n-4+p)||chk(p)) p++;
    		for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (i==j) printf("%d ",p);
                    else printf("4 ");
                }
                cout<<endl;
            } 
        }
    }