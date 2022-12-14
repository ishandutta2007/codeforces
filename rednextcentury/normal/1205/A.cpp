#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    if (n%2==0)cout<<"NO"<<endl;
    else
    {
        int l=1,r=2*n;
        int cur=0;
        for (int i=0;i<2*n;i++)
        {
            if (a[i]==0)
            {
                if (cur%2==0)
                    a[i]=l,a[(i+n)%(2*n)]=l+1,l+=2;
                else
                    a[i]=r,a[(i+n)%(2*n)]=r-1,r-=2;
                cur=1-cur;
            }
        }
        cout<<"YES"<<endl;
        for (int i=0;i<2*n;i++)
            cout<<a[i]<<' ';
    }
}