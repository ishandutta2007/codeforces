                    #include <bits/stdc++.h>
                    using namespace std;
                    long long dp[2000][2000];
                    int mn[2000][2000];
                    long long mod=998244353;
                    int L[10000];
                    int R[10000];
                    int a[2000];
                    int main()
                    {
                        //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
                        int n,m;
                        scanf("%d%d",&n,&m);
                        int tot=1;
                        for (int i=1;i<=m;i++)
                        {
                            int x;
                            scanf("%d",&x);
                            if (a[tot-1]!=x)a[tot++]=x;
                        }
                        tot--;
if (tot>=1200){
cout<<0<<endl;
return 0;
}
                        for (int i=1;i<=tot;i++){
                            if (L[a[i]]==0)L[a[i]]=i;
                            R[a[i]]=i;
                            dp[i][i-1]=1,dp[i+1][i]=1;
                            mn[i][i]=i;
                            for (int j=i+1;j<=tot;j++)
                                mn[i][j]=(a[j]<a[mn[i][j-1]])?j:mn[i][j-1];
                        }
                        for (int i=1;i<=tot;i++)
                        {
                            if (L[a[i]]==i && R[a[i]]==i)dp[i][i]=1;
                        }
                        for (int i=1;i<=tot;i++)
                            for (int j=i+1;j<=tot;j++)
                                mn[i][j]=(a[j]<a[mn[i][j-1]])?j:mn[i][j-1];
                        for (int i=2;i<=tot;i++)
                        {
                            for (int l=1;l+i-1<=tot;l++)
                            {
                                int r = i+l-1;
                     
                                int c = mn[l][r];
                                int v = a[c];
                                if (R[v]>r || L[v]<l){
                    dp[l][r]=0;
                    continue;
                    }
                                long long LL=0,RR=0;
                                long long MM=1;
                                int last=L[v];
                                for (int i=L[v]+1;i<=R[v];i++)
                                {
                                    if (a[i]==v)
                                    {
                                        if (last+1<i)
                                            MM*=dp[last+1][i-1],MM%=mod;
                                        last=i;
                                    }
                                }
                                for (int j=L[v];j>=l;j--)
                                    LL+=(dp[l][j-1]*dp[j][L[v]-1])%mod;
                                LL%=mod;
                                for (int j=R[v];j<=r;j++)
                                    RR+=(dp[R[v]+1][j]*dp[j+1][r])%mod;
                                RR%=mod;
                                dp[l][r]=(((LL*RR)%mod)*MM)%mod;
                            }
                        }
                        cout<<dp[1][tot]<<endl;
                     
                     }