#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long d,l,r;
        cin>>l>>r>>d;
        if (d<l)cout<<d<<endl;
        else cout<<(r/d+1)*d<<endl;
    }
}