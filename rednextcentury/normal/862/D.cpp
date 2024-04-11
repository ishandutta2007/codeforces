#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tot=0;
bool inv;
string q;
int n;
int numOnes(int l,int r)
{
    q="";
    for (int i=0;i<n;i++)
    {
        if (i>=l && i<=r)
            q+="1";
        else
            q+="0";
    }
    if (inv)for (int i=0;i<n;i++)q[i]='1'-q[i]+'0';
    cout<<'?'<<' '<<q<<endl;
    fflush(stdout);
    int ret;
    cin>>ret;
    int num = ret - tot;
    for (int i=0;i<=n;i++)
    {
        if (i+i+num==(r-l+1))
            return i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=0;i<n;i++)q+="0";
    cout<<"? "<<q<<endl;
    fflush(stdout);
    cin>>tot;
    int p = numOnes(0,0);
    if (p==1)inv=1,tot=n-tot;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int nn = numOnes(l,mid);
        if (nn>0)
        {
            ans=mid,r=mid-1;
        }
        else
            l=mid+1;
    }
    if (inv)
    {
        cout<<"! "<<ans+1<<' '<<1<<endl;
        fflush(stdout);
    }
    else
    {
        cout<<"! "<<1<<' '<<ans+1<<endl;
        fflush(stdout);
    }
}