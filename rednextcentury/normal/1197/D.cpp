        #include <bits/stdc++.h>
        using namespace std;
        long long a[1000000];
        long long best[101];
        int main()
        {
            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
            int n,m;
            long long k;
            cin>>n>>m>>k;
            for (int i=1;i<=n;i++)
                cin>>a[i];
            for (int i=0;i<m;i++)
                best[i]=1e17;
            best[0]=0;
            long long ret=0;
            long long sum=0;
            for (int i=1;i<=n;i++)
            {
                sum+=a[i];
                long long cur = 0;
                for (int j=0;j<m;j++)
                {
                    int addToNum=((i%m)!=j);
                    if (i%m<j)addToNum=0;
                    cur=max(cur,sum-(k*(i/m)) - best[j] - k*addToNum);
                }
                ret=max(ret,cur);
                best[i%m]=min(best[i%m],sum-(k*(i/m)));
            }
            cout<<ret<<endl;
        }