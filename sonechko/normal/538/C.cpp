#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int l1=0,r1=0;
    int ans=0;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        if (i==1) {ans=max(ans,l-1+r);} else
        {
            if (r1<r&&l-l1<r-r1) {cout<<"IMPOSSIBLE"<<endl; return 0;}
            if (r<r1&&l-l1<r1-r) {cout<<"IMPOSSIBLE"<<endl; return 0;}
            int ll=max(r,r1),rr=2e8;
            while (rr-ll>1)
            {
                int mid=(ll+rr)/2;
                if (abs(r-mid)+abs(r1-mid)<=l-l1) ll=mid; else rr=mid;
            }
            int mid=rr;
            if (abs(r-mid)+abs(r1-mid)<=l1-l) ans=max(ans,rr); else
                ans=max(ans,ll);
        }
        l1=l;
        r1=r;
    }
    ans=max(ans,n-l1+r1);
    cout<<ans<<endl;
}