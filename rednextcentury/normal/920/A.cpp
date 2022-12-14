#include <bits/stdc++.h>
using namespace std;
int x[10000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for (int i=0;i<k;i++)
            cin>>x[i];
        int ret=max(x[0],n-x[k-1]+1);
        for (int i=1;i<k;i++)
        {
            ret=max(ret,(x[i]-x[i-1]+1)/2+(x[i]-x[i-1]+1)%2);
        }
        cout<<ret<<endl;
    }
}