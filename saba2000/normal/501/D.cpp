#include<bits/stdc++.h>
using namespace std;
int a[200009],b[300009],a1[300009],b1[200009],c[200009];
int f[200009];
int n;
void upd (int x)
{x++;
    while(x<=n)
        f[x]++,x+=(x&-x);

}
int cnt(int x)
{x++;
    int sum=0;
    while(x>0)
        sum+=f[x],x-=(x&-x);
    return sum;
}
main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for (int i=0; i<n; i++)
        scanf("%d",&b[i]);
    for (int i=n-1; i>=0; i--)
    {
        a1[i]=cnt(a[i]);
        upd(a[i]);
    }
    for (int i=0; i<=n; i++)
        f[i]=0;
    for (int i=n-1; i>=0; i--)
    {
        b1[i]=cnt(b[i]);
        upd(b[i]);
    }
     for (int i=0; i<=n; i++)
        f[i]=0;
    for (int i=n-1; i>=0; i--)
    {
        int x=(n-i);
        c[i]+=a1[i]+b1[i];
        if(i) c[i-1]+=c[i]/x;
        c[i]%=x;
    }
    set<int> S;
    for (int i=0 ;i<n; i++)
        S.insert(i);
    for (int i=0; i<n; i++)
    {
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(mid-cnt(mid-1)>c[i]) r=mid-1;
            else l=mid;
        }auto it=S.lower_bound(l);
        int x=*it;
        S.erase(it);
        printf("%d ",x);
        upd(x);
    }
}