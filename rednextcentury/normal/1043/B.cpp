#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],b[i-1]=a[i]-a[i-1];
        vector<int> vec;
    for (int k=1;k<=n;k++)
    {
        bool ok=1;
        for (int j=0;j<n;j++)
        {
            if (b[j]!=b[j%k])
                ok=0;
        }
        if(ok)vec.push_back(k);
    }
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)cout<<vec[i]<<' ';
}