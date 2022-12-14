#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int l=0,r=n-1;
    while(l<n && a[l]==0)
        l++;
    while(r>=0 && a[r]==0)
        r--;
    if (l==n)
    {
        cout<<0<<endl;
        return 0;
    }
    n=r-l+1;
    int num=0,cur=1;
    for (int i=l;i<=r;i++)
    {
        if (a[i]==cur)
            num++;
        else
        {
            if (cur==1)
            {
                cur=0;
                num=1;
            }
            else if (num>1)
                n-=num,cur=1,num=1;
            else
                cur=1,num=1;
        }
    }
    cout<<n<<endl;
}