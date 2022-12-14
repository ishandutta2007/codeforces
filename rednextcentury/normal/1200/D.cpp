#include <bits/stdc++.h>
using namespace std;
int mxC[10000];
int mnC[10000];
int mxR[10000];
int mnR[10000];
int a[3001][3001];
int add[3001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        mnR[i]=n+1,mnC[i]=n+1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            if (x=='B')
                a[i][j]=1;
            else a[i][j]=0;
            if (a[i][j]==1)
            {
                mxR[i]=max(mxR[i],j);
                mnR[i]=min(mnR[i],j);
                mxC[j]=max(mxC[j],i);
                mnC[j]=min(mnC[j],i);
            }
        }
    }
    int ret=0;
    for (int i=1;i<=n-k+1;i++)
    {
        for (int j=1;j<=n;j++)add[j]=0;
        int c1=1,c2=0;
        int r1=i,r2=i+k-1;
        int cur=0;
        for (int r=r1;r<=r2;r++)
        {
            int L = mxR[r];
            int R = mnR[r]+k-1;
            R=min(R,n);
            if (L<=R)add[L]++,add[R+1]--;
        }
        while(c2<k)
        {
            c2++;
            if (mnC[c2]>=r1 && mxC[c2]<=r2 && mnC[c2]<=mxC[c2])cur++;
            cur+=add[c2];
            ret=max(ret,cur);
        }
        while(c2<n)
        {
            c2++;
            if (mnC[c2]>=r1 && mxC[c2]<=r2 && mnC[c2]<=mxC[c2])cur++;
            if (mnC[c1]>=r1 && mxC[c1]<=r2 && mnC[c1]<=mxC[c1])cur--;
            c1++;
            cur+=add[c2];
            ret=max(ret,cur);
        }

    }
    for (int i=1;i<=n;i++)
        ret+=(mnC[i]==n+1)+(mnR[i]==n+1);
    cout<<ret<<endl;
}