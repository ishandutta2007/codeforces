#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> ret;
int main ()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=n-1;i>=0;i--)
    {
        if (k>0)
        {
            k--;
            cout<<1<<' '<<a[i]<<endl;
        }
    }
    for (int i=n-1;i>=0;i--)
    {
        ret.push_back(a[i]);
        for (int j=i-1;j>=0;j--)
        {
            if (k>0)
            {
                k--;
                cout<<ret.size()+1<<' ';
                for (int x=0;x<ret.size();x++)
                    cout<<ret[x]<<' ';
                cout<<a[j]<<endl;
            }
        }
    }
}