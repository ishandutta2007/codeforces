#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int mx1=0,mx2=0;
    for (int i=0;i<n;i++)
    {
        int x,y;
        char t;
        cin>>t>>x>>y;
        if (x>y)swap(x,y);
        if (t=='+')mx1=max(mx1,x),mx2=max(mx2,y);
        if (t=='?')
        {
            if (mx1<=x && mx2<=y)
                cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}