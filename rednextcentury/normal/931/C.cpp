#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int a[1000000];
int b[1000000];
int c[1000000];
int main()
{
    int n;
    cin>>n;
    int mn= 1000000000;
    int mx=-1000000000;
    int mnC = 0;
    int mxC = 0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]<mn)mn=a[i],mnC=0;
        if (a[i]>mx)mx=a[i],mxC=0;
        if (a[i]==mn)mnC++;
        if (a[i]==mx)mxC++;
    }
    if (mn+2>mx)
    {
        cout<<n<<endl;
        for (int i=0;i<n;i++)
            cout<<a[i]<<' ';
        return 0;
    }
    if (min(mnC,mxC) > (n-mnC-mxC)/2)
    {
        sort(a,a+n);
        int l=0,r=n-1;
        int eq=n;
        while(l<r && a[l]+2==a[r])
        {
            a[r]=a[l]+1;
            a[l]=a[l]+1;
            l++,r--;
            eq-=2;
        }
        cout<<eq<<endl;
        for (int i=0;i<n;i++)
            cout<<a[i]<<' ';
        return 0;
    }
    else
    {
        bool c=0;
        int num = n-mxC-mnC;
        num/=2;
        num*=2;
        int x=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]==mn+1 && num)
            {
                if (c)a[i]=mn;
                else a[i]=mx;
                num--;
                c=!c;
                x++;
            }
        }
        cout<<n-x<<endl;
        for (int i=0;i<n;i++)
            cout<<a[i]<<' ';
        return 0;
    }
}