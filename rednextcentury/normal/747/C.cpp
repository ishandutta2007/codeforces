#include<bits/stdc++.h>
using namespace std;
bool has[2000001];
int k[2000001];
int d[2000001];
int ok[202];
int main()
{
    int n,q;
    cin>>n>>q;
    int mx=0;
    for (int i=0;i<q;i++)
    {
        int t,K,D;
        cin>>t>>K>>D;
        has[t]=1;
        k[t]=K;
        d[t]=D;
        mx=max(mx,t);
    }
    for (int i=0;i<=mx;i++)
    {
        if (has[i])
        {
            int sum=0;
            int p=0;
            for (int j=0;j<n;j++)
            {
                if (ok[j]<=i)p++;
            }
            if (p<k[i])
            {
                cout<<-1<<endl;
                continue;
            }
            for (int j=0;j<n;j++)
            {
                if (ok[j]<=i)
                {
                    sum+=j+1;
                    k[i]--;
                    ok[j]=d[i]+i;
                    if (k[i]==0)break;
                }
            }
            if (k[i]==0)
            {
                printf("%d\n",sum);
            }
            else
                printf("-1\n");
        }
    }
}