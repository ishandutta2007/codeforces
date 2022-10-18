#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (t+l<=500)
        {
            cout<<"A";
            t+=l;
        } else
        {
            t-=r;
            cout<<"G";
        }
    }
    cout<<"\n";
}