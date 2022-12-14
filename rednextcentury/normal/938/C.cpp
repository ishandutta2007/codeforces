#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        bool is=0;
        for (int i=1;i<=50000;i++)
        {
            int n=i;
            int m=-1;
            int l=1,r=i;
            int ret=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int p = n*n-(n/mid)*(n/mid);
                if (p>=x)
                    ret=p,m=mid,r=mid-1;
                else
                    l=mid+1;
            }
            if (ret==x)
            {
                is=1;
                cout<<n<<' '<<m<<endl;
                break;
            }
        }
        if (!is)cout<<-1<<endl;
    }
}