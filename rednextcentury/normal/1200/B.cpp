#include <bits/stdc++.h>
using namespace std;
int h[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    int t;
    cin>>t;
    while(t--)
    {

        cin>>n>>m>>k;
        for (int i=0;i<n;i++)
            cin>>h[i];
        int cur=m;
        bool ok=1;
        for (int i=0;i+1<n;i++)
        {
            int goal = max(0,h[i+1]-k);
            cur+=h[i]-goal;
            if (cur<0)ok=0;
        }
        if (ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}