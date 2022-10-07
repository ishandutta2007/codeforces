#include<bits/stdc++.h>
using namespace std;
int d[100009];
main()
{//...4
    int n,m,c;
    cin>>n>>m>>c;
    int k=n+1,p=0;
    d[k]=100000000;
    d[0]=-1;
    while(m--)
    {
        int x;
        cin>>x;
        if(x>c/2)
        {

        if(x<=d[k])
        {
            k--;
            d[k]=x;
            cout<<k<<endl;
            if(k==p+1) return 0;
        }
         else
        {
            int l=k,r=n+1;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(d[mid]>=x) r=mid;
                else l=mid+1;
            }
            cout<<l-1<<endl;;
            d[l-1]=x;
        }
        }
        else
        if(x>=d[p])
        {
            p++;
            d[p]=x;
            cout<<p<<endl;
            if(k==p+1) return 0;
        }
        else
        {
            int l=0,r=p;
            while(l<r)
            {
                int mid=(l+r+1)/2;
                if(d[mid]<=x) l=mid;
                else r=mid-1;
            }
            cout<<l+1<<endl;;
            d[l+1]=x;
        }
    }
//2 4

}