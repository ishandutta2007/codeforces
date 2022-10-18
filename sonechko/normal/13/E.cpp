#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
int a[N],num[N],fir[400],ans,res,sec[400],sz,p,n,m,i,ans1[N],ans2[N],j,ik,type1,l,r;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    p=sqrt(n);
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        num[i]=(i-1)/p+1;
        sz=num[i];
        if (fir[num[i]]==0) fir[num[i]]=i;
        sec[num[i]]=i;
    }
    for (i=1; i<=sz; i++)
    {
        for (j=sec[i]; j>=fir[i]; j--)
        if (j+a[j]>sec[i])
        {
            if (j+a[j]>n) ans2[j]=-1; else ans2[j]=j+a[j];
            ans1[j]=1;
        } else
        {
            ans1[j]=ans1[j+a[j]]+1;
            ans2[j]=ans2[j+a[j]];
            if (ans2[j]==-1) {ans1[j]--; ans2[j]=j+a[j];}
        }
    }
    for (ik=1; ik<=m; ik++)
    {
        cin>>type1;
        if (type1==0)
        {
            cin>>l>>r;
            a[l]=r;
            i=num[l];
            for (j=l; j>=fir[i]; j--)
                if (j+a[j]>sec[i])
                    {
                        if (j+a[j]>n) ans2[j]=-1; else ans2[j]=j+a[j];
                        ans1[j]=1;
                    } else
                    {
                        ans1[j]=ans1[j+a[j]]+1;
                        ans2[j]=ans2[j+a[j]];
                        if (ans2[j]==-1) {ans1[j]--;
                        ans2[j]=j+a[j];}
                    }
        } else
        {
            cin>>l;
            ans=0;
            res=l;
            while (1==1)
            {
                ans+=ans1[l];
                res=l;
                if (ans2[l]==-1) break;
                l=ans2[l];
            }
            cout<<res<<" "<<ans<<"\n";
        }
    }
}