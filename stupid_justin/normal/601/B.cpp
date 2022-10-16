//1
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,q,ans;
int L[N],R[N];
int st[N];
int top;
int pos[N];
int h[N],dt[N];
signed main()
{
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n-1;i++)
        dt[i]=abs(h[i+1]-h[i]);
    while (q--)
    {
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        int l,r;
        cin>>l>>r;
        r--;
        ans=0;
        for (int i=l;i<=r;i++)
            dt[i-l+1]=abs(h[i+1]-h[i]);
        int RR=r-l+1;
        //[1,RR]
        for (int i=1;i<=RR;i++)
        {
            while (top!=0 && st[top]<dt[i])
            {
                R[pos[top]]=i-pos[top];
                top--;
            }
            L[i]=i-pos[top];
            st[++top]=dt[i];
            pos[top]=i;
        }
        while (top) R[pos[top]]=RR+1-pos[top],top--;
        for (int i=1;i<=RR;i++) ans+=dt[i]*L[i]*R[i];
        cout<<ans<<endl;
    }
}