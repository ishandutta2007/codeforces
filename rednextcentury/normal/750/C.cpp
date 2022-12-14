#include <bits/stdc++.h>
using namespace std;
int mn[1000000],mx[1000000];
int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    int sum=0;
    int l=-1000000000,r=1000000000;
    int i=0;
    while(n--)
    {
        int d,c;
        cin>>c>>d;
        if (d==1)
        {
            mn[i]=1900-sum,mx[i]=1000000000;
        }
        else
        {
            mn[i]=-1000000000,mx[i]=1899-sum;
        }
        l=max(l,mn[i]);
        r=min(r,mx[i]);
        sum+=c;
        i++;
    }
    if (l>r)
        cout<<"Impossible"<<endl;
    else if (r==1000000000)
        cout<<"Infinity"<<endl;
    else cout<<r+sum<<endl;
}