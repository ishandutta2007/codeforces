    #include <bits/stdc++.h>
    using namespace std;
    int n;
    int is[101];
    int a[101];
    int x;
    int l,r;
    int ans=0;
    void solve(int i)
    {
        if (i==n)
        {
            bool p=1;
            int mn=10000000,mx=-1;
            int k=0;
            for (int j=0;j<n;j++)
            {
                if (is[j]==0)
                    continue;
                k+=a[j];
                mn=min(mn,a[j]);
                mx=max(mx,a[j]);
            }
            if (k>=l && k<=r)
            {


            if (mx-mn>=x)
            {
                ans++;
            }
            }
        }
        else
        {
            is[i]=1;
            solve(i+1);
            is[i]=0;
            solve(i+1);
        }
    }
    int main()
    {
        cin>>n>>l>>r>>x;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve(0);
        cout<<ans<<endl;
    }