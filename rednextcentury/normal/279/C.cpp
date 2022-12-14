#include<bits/stdc++.h>
using namespace std;
int inc[1000000];
int Dec[1000000];
int lad[1000000];
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (i!=0)
        {
            if (a[i]>=a[i-1])inc[i]=inc[i-1];
            else inc[i]=i;
            if (a[i]<=a[i-1])Dec[i]=Dec[i-1];
            else Dec[i]=i;
        }
        lad[i]=inc[Dec[i]];
    }
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        if (lad[r]<=l)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}